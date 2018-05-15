/**
 * Author: Jake Murphy Smith
 * Date:   26-03-2018
 * Filename: rendezvous.cpp
 * Last modified by:   Jake Murphy Smith
 * Last modified time: 26-03-2018
 * License: GNU GENERAL PUBLIC LICENSE
 */

#include "Semaphore.h"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>


const int NUMBER_OF_THREADS = 6;

/*!
 * Creating a job for the first thread
 */
void firstThreadTask(std::shared_ptr<Semaphore> barrierOne, std::shared_ptr<Semaphore> barrierTwo, int threadNumber){
    std::cout <<  std::to_string(threadNumber) + " arrived, waiting barrierOne" << std::endl;
    barrierOne->Wait();
    std::cout << std::to_string(threadNumber) + " no longer waiting, signal barrierTwo" << std::endl;
    barrierTwo->Signal();
}

/*!
 * Creating a job for the second thread
 */
void secondThreadTask(std::shared_ptr<Semaphore> barrierOne, std::shared_ptr<Semaphore> barrierTwo, int threadNumber){
  std::cout << std::to_string(threadNumber) + " arrived and signalled barrierOne, wait barrierTwo" << std::endl;
    barrierOne->Signal();
    barrierTwo->Wait();
    std::cout << std::to_string(threadNumber) + " goes next" << std::endl;
}

/*!
 * Initializing a vector of threads to demonstrate barriers
 */
void createThreads(std::vector<std::thread> &threadPool, std::shared_ptr<Semaphore> barrierOne, std::shared_ptr<Semaphore> barrierTwo){
    for (int i = 0; i < NUMBER_OF_THREADS; ++i){
        std::this_thread::sleep_for(std::chrono::milliseconds(125));
        if (i < 3){
            std::thread curThread = std::thread(firstThreadTask, barrierOne, barrierTwo, i);
            threadPool.push_back(move(curThread));
        }else{
            std::thread curThread = std::thread(secondThreadTask, barrierOne, barrierTwo, i);
            threadPool.push_back(move(curThread));
        }
    }
}

/*!
 * Main function
 */
int main(void){

    /*!
     * Creating all variables needed for rendezvous
     */
    std::shared_ptr<Semaphore> barrierOne(new Semaphore);
    std::shared_ptr<Semaphore> barrierTwo(new Semaphore);
    std::vector<std::thread> threadPool;
    
    createThreads(threadPool, barrierOne, barrierTwo);

    /*!
     * Call join on threads to terminate
     */
    for(std::thread &threadedWheat: threadPool){
        threadedWheat.join();
    }
    return 0;
}
