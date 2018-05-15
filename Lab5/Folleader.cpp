/*!
author: Jake Murphy Smith
date: 21/10/17
task: to implement leader follower pattern
version: 1.0
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskLeader(std::shared_ptr<Semaphore> leaderQ,std::shared_ptr<Semaphore> followerQ, std::shared_ptr<Semaphore> rendezvous, std::shared_ptr<Semaphore> mutex, int *leaders, int *followers){
  mutex->Wait();
  if( *followers > 0)
    {
      *followers--;
      followerQ->Signal();/*!wake up a sleeping follower */
    }
  else
    {
      *leaders++;
      mutex->Signal();
      leaderQ->Wait();
    }
  /*! the threads dance */
  rendezvous->Wait();/*!prevent more than 2 from dancing*/
  mutex->Signal();
  std::cout << "Pair have danced" << std::endl;
}

void taskFollower(std::shared_ptr<Semaphore> leaderQ,std::shared_ptr<Semaphore> followerQ, std::shared_ptr<Semaphore> rendezvous, std::shared_ptr<Semaphore> mutex, int *leaders, int *followers){
  mutex->Wait();
  if( *leaders > 0)
    {
      *leaders--;
      leaderQ->Signal();/*!wake up a sleeping leader */
    }
  else
    {
      *followers++;
      mutex->Signal();
      followerQ->Wait();
    }
  /*! the threads dance*/
  rendezvous->Signal();/*!prevent more than 2 from dancing*/
}

int main(void){
  std::thread threadOne, threadTwo;//, threadThree, threadFour;
  std::shared_ptr<Semaphore> leaderQ(new Semaphore);//control leaders
  std::shared_ptr<Semaphore> followerQ(new Semaphore);//control followers
  std::shared_ptr<Semaphore> mutex(new Semaphore(1));//control access to critical section
  std::shared_ptr<Semaphore> rendezvous(new Semaphore);
  int leaders = 0;
  int followers = 0;
  /**< Launch the threads  */
  threadOne=std::thread(taskLeader, leaderQ, followerQ , rendezvous, mutex, &leaders, &followers);
  threadTwo=std::thread(taskFollower, leaderQ, followerQ, rendezvous, mutex, &leaders, &followers);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
