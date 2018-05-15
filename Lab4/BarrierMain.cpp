/**
 * Author: Jake Murphy Smith
 * Date:   26-03-2018
 * Filename: BarrierMain.cpp
 * Last modified by:   Jake Murphy Smith
 * Last modified time: 26-03-2018
 * License: GNU GENERAL PUBLIC LICENSE
 */

#include "Barrier.h"
#include <iostream>
#include <thread>
#include <mutex>

/*
  \\Program that demonstrates an example of a reusable barrier.
*/

void taskOne(std::shared_ptr<Barrier> reusable){
  	std::cout << "first test" << std::endl;
  	reusable->firstTurnstile();
	std::cout << "second test" << std::endl;
	reusable->finalTurnstile();
}
/*!
 *  Main to put class to put barrier to use
 *  Implemented using array instead of vector of threads this time to see
 *  If any behavioural changes/performance improvement/drop etc
 */

int main(void){
  int numThreads = 5;
  std::thread threadPool[numThreads];/*! instantiating with number of threads*/
  std::shared_ptr<Barrier> reusable(new Barrier(numThreads));/*! instantiate barrier */
  
  /*! Instantiate the threads  */
  for(int i = 0; i < numThreads; ++i){
    threadPool[i] = std::thread(taskOne, reusable);
  }
  /*! Murder the threads */
  for(int i = 0; i < numThreads; ++i){
    threadPool[i].join(); 
  }
  std::cout << "All Threads Finished, back in mainThreads have executed"<< std::endl ;
  return 0;
}
