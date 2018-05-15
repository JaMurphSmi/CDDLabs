/**
 * Author: Jake Murphy Smith
 * Date:   26-03-2018
 * Filename: Signal.cpp
 * Last modified by:   Jake Murphy Smith
 * Last modified time: 26-03-2018
 * License: GNU GENERAL PUBLIC LICENSE
 */

#include "Semaphore.h"
#include <vector>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

//! Odd number of threads was causing deadlock, change to even
const int NUMBER_OF_THREADS = 6;


//!  Task to be done by first thread
void firstThreadTask(std::shared_ptr<Semaphore> semaphore, int threadNumber){
    std::cout << "Thread " + std::to_string(threadNumber) + " will go first " << std::endl;
    semaphore->Signal();
}

//! Task to be done by second thread
void secondThreadTask(std::shared_ptr<Semaphore> semaphore, int threadId){
    semaphore->Wait();
    std::cout << "Thread " + std::to_string(threadId) + " will go second " << std::endl;
}

void createThreads(std::vector<std::thread> &threadPool, std::shared_ptr<Semaphore> semaphore) {
  for (int i = 0; i < NUMBER_OF_THREADS; i++){
      std::this_thread::sleep_for(std::chrono::milliseconds(250));
      if (i < 3){//! ie 0,1,2 sent to second task, 3,4,5 sent to first task
            std::thread current = std::thread(secondThreadTask, semaphore, i);
            threadPool.push_back(move(current));
      }else{//! these threads 'wake up' other threads that are waiting
            std::thread current = std::thread(firstThreadTask, semaphore, i);
            threadPool.push_back(move(current));
        }
    }
}

int main(void){
  //! redoing lab with a new style
  //! attempting to show semaphores operating using threads
    std::shared_ptr<Semaphore> semaphore (new Semaphore);
    std::vector<std::thread> threadPool;

    createThreads(threadPool, semaphore);
    
    //! enhanced for through each thread of threadPool
    for(std::thread &threadedWheat: threadPool){
      threadedWheat.join();//! join to main thread and terminate
    }
}
