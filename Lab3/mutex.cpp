/**
 * Author: Jake Murphy Smith
 * Date:   26-03-2018
 * Filename: mutex.cpp
 * Last modified by:   Jake Murphy Smith
 * Last modified time: 26-03-2018
 * License: GNU GENERAL PUBLIC LICENSE
 */

#include "Semaphore.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <string>

const int NUM_THREADS = 5;//! max num of threads to be created
int shared = 0;

/**
 *
 * task: to demonstrate mutual exclusion
 */



void taskOne(std::shared_ptr<Semaphore> mut)
{
  mut->Wait();
  std::cout << "Value of shared number " << shared << std::endl;
  ++shared;
  std::cout << "After increment " << shared << std::endl;
  mut->Signal();
}
//void taskTwo(std::shared_ptr<Semaphore> mut, int *shared)
//{
//  mut->Wait();
//  std::cout << "Value of shared number "<< *shared << std::endl;
//  ++*shared;
//  std::cout << "After increment ";
//  std::cout << *shared << std::endl;
//  mut->Signal();
//}

void createThreads(std::vector<std::thread> &threadPool, std::shared_ptr<Semaphore> mutex){
    for (int i = 0; i < NUM_THREADS; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
	// make sleep to allow threads time to be created
	  std::thread current = std::thread(taskOne, mutex);
            threadPool.push_back(move(current));
        }
}

int main(void){
  
  std::thread threadOne, threadTwo;
  //!making a vector to show multiple increments hopefully
  std::vector<std::thread> threadPool;
  std::shared_ptr<Semaphore> mutex( new Semaphore(1));
  
  //int shared = 0;

  /**< Launch the threads in main */
  //threadOne=std::thread(taskTwo,mutex,&shared);
  //threadTwo=std::thread(taskOne,mutex,&shared);
  createThreads(threadPool, mutex);//realized I named previous one createVectors

  for(std::thread &threadedWheat: threadPool){
      threadedWheat.join();
    }
  
  std::cout << "Launched from the main\n";
  std::cout << shared << std::endl;
  //threadOne.join();
  //threadTwo.join();
  return 0;
}
