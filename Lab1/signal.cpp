

#include "Semaphore.h"
#include <vector>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

//! Denotes the maximum number of threads that can be made
const int NUMBER_OF_THREADS = 5;


//!  Task to be done by first thread
void firstThreadTask(std::shared_ptr<Semaphore> semaphore, int threadId){
    std::cout << "Thread " + std::to_string(threadId) + " will go first " << std::endl;
    semaphore->Signal();
}

//! Task to be done by second thread
void secondThreadTask(std::shared_ptr<Semaphore> semaphore, int threadId){
    semaphore->Wait();
    std::cout << "Thread " + std::to_string(threadId) + " will go second " << std::endl;
}


//! Initializing vector of threads
void createThreads(std::vector<std::thread> &threadPool, std::shared_ptr<Semaphore> semaphore){
    for (int i = 0; i < NUMBER_OF_THREADS; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        if (i < 5){
            std::thread current = std::thread(secondThreadTask, semaphore, i);
            threadPool.push_back(move(current));
        }else{
            std::thread current = std::thread(firstThreadTask, semaphore, i);
            threadPool.push_back(move(current));
        }
    }
}


int main(){
  //! attempting to show semaphores operating using threads
    std::shared_ptr<Semaphore> semaphore (new Semaphore);
    std::vector<std::thread> threadPool;

    createThreads(threadPool, semaphore);
    //! enhanced for through each thread of threadPool
    for(std::thread &threadedWheat: threadPool){
      threadedWheat.join();//! join to main thread and terminate
    }
}
