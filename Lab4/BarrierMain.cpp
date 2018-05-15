<<<<<<< HEAD
/**
 * Author: Jake Murphy Smith
 * Date:   26-03-2018
 * Filename: BarrierMain.cpp
 * Last modified by:   Jake Murphy Smith
 * Last modified time: 26-03-2018
 * License: GNU GENERAL PUBLIC LICENSE
 */
=======
/*! 
  \\ Author: Jake Murphy Smith
  \\ Date: 24th March 2018
  \\ License Employed: GNU General Public License v3.0
  \\ brief A Semaphore Implementation to demonstrate a reusable barrier 
  \									
  \\ 

*/

>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3

#include "Barrier.h"
#include <iostream>
#include <thread>
#include <mutex>

/*
<<<<<<< HEAD
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
=======
  \\Function that demonstrates reusable barrier.
*/

void taskOne(std::shared_ptr<Barrier> rb){
  	std::cout << "first test" << std::endl;
  	rb->FirstPhase();
	std::cout << "second test" << std::endl;
	rb->SecondPhase();
}
/*!
  Driver to show the reusable barrier class in operation
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
 */

int main(void){
  int numThreads = 5;
<<<<<<< HEAD
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
=======
  std::thread threadArr[numThreads] ;
  std::shared_ptr<Barrier> rb(new Barrier(numThreads));
  
  /**< Launch the threads  */
  for(int i = 0; i < numThreads; i++ ){
    threadArr[i] = std::thread(taskOne, rb);
  }
  for(int i =0; i <numThreads; i++){
    threadArr[i].join(); 
  }
  std::cout << "All Threads Finished, back in main"<< std::endl ;
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
  return 0;
}
