/*!
author: Jake Murphy Smith
date: 24/10/17
task: to implement dining philosopher pattern
version: 1.0
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>

void eat(){
  std::cout << "A Philosopher is eating" << std::endl;

int main(void){
  std::thread threadOne, threadTwo, threadThree, threadFour, threadFive;
  /**< Launch the threads  */
  threadOne=std::thread(taskLeader, leaderQ, followerQ , rendezvous, mutex, &leaders, &followers);
  threadTwo=std::thread(taskFollower, leaderQ, followerQ, rendezvous, mutex, &leaders, &followers);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  threadThree.join();
  threadFour.join();
  threadFive.join();
  return 0;
}
