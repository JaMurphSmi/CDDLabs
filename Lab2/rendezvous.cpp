<<<<<<< HEAD
/**
 * Author: Jake Murphy Smith
 * Date:   26-03-2018
 * Filename: rendezvous.cpp
 * Last modified by:   Jake Murphy Smith
 * Last modified time: 26-03-2018
 * License: GNU GENERAL PUBLIC LICENSE
 */
=======
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3

#include "Semaphore.h"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

<<<<<<< HEAD
const int NUMBER_OF_THREADS = 6;
=======
const int SIZE = 10;
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3

/*!
 * Creating a job for the first thread
 */
<<<<<<< HEAD
void firstThreadTask(std::shared_ptr<Semaphore> barrierOne, std::shared_ptr<Semaphore> barrierTwo, int threadNumber){
    std::cout <<  std::to_string(threadNumber) + " arrived, waiting barrierOne" << std::endl;
    barrierOne->Wait();
    std::cout << std::to_string(threadNumber) + " no longer waiting, signal barrierTwo" << std::endl;
=======
void firstThreadTask(std::shared_ptr<Semaphore> barrierOne, std::shared_ptr<Semaphore> barrierTwo, int threadId){
    std::cout << "Thread " + std::to_string(threadId) + " arrived and WAITING" << std::endl;
    barrierOne->Wait();
    std::cout << "--- Thread " + std::to_string(threadId) + " RELEASED" << std::endl;
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
    barrierTwo->Signal();
}

/*!
<<<<<<< HEAD
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
=======
 * Creating a job for the Second thread
 */
void secondThreadTask(std::shared_ptr<Semaphore> barrierOne, std::shared_ptr<Semaphore> barrierTwo, int threadId){
    std::cout << "Thread " + std::to_string(threadId) + " arived and SIGNALLING" << std::endl;
    barrierOne->Signal();
    barrierTwo->Wait();
    std::cout << "--- Thread " + std::to_string(threadId) + " goes AFTER" << std::endl;
}

/*!
 * Initializing a vector with a threads evently adding
 * thread jobs to it
 *
 * params:
 * threads - vector with threads
 * barrierOne - Semaphore
 * barrierTwo - Semaphore
 */
void createVectors(std::vector<std::thread> &threadPool, std::shared_ptr<Semaphore> barrierOne, std::shared_ptr<Semaphore> barrierTwo){
    for (int i = 0; i < SIZE; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        if (i < 5){
            std::thread current = std::thread(firstThreadTask, barrierOne, barrierTwo, i);
            threadPool.push_back(move(current));
        }else{
            std::thread current = std::thread(secondThreadTask, barrierOne, barrierTwo, i);
            threadPool.push_back(move(current));
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
        }
    }
}

/*!
 * Main function
 */
int main(void){

    /*!
<<<<<<< HEAD
     * Creating all variables needed for rendezvous
     */
    std::shared_ptr<Semaphore> barrierOne(new Semaphore);
    std::shared_ptr<Semaphore> barrierTwo(new Semaphore);
    std::vector<std::thread> threadPool;
    
    createThreads(threadPool, barrierOne, barrierTwo);

    /*!
     * Call join on threads to terminate
=======
     * Two Semaphores for use in rendezvous
     */
    std::shared_ptr<Semaphore> barrierOne(new Semaphore);
    std::shared_ptr<Semaphore> barrierTwo(new Semaphore);

    /*!
     * creating a vector containing threads
     */
    std::vector<std::thread> threadPool;
    createVectors(threadPool, barrierOne, barrierTwo);

    /*!
     * Calling join on threads to terminate
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
     */
    for(std::thread &threadedWheat: threadPool){
        threadedWheat.join();
    }
    return 0;
}
