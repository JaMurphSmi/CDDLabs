<<<<<<< HEAD
/**
 * Author: Jake Murphy Smith
 * Date:   26-03-2018
 * Filename: Barrier.cpp
 * Last modified by:   Jake Murphy Smith
 * Last modified time: 26-03-2018
 * License: GNU GENERAL PUBLIC LICENSE
 */

=======
/*!
author: Jake Murphy Smith
date: 29/10/17
task: to create a reusable barrier
version: 1.0
 */
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
#include "Barrier.h"
#include <iostream>
#include <mutex>
/*!
<<<<<<< HEAD
  Orginally one block, however logic was getting too annoying to follow
  partitioned out to smaller chunks
 */


/*!
  firstTurnstile stands as the first block that the threadPool will reach and be held at until all have arrived
 */
void Barrier::firstTurnstile(){
  	mutex->Wait();
	count++;
	if(count == n){
	  turnStileB->Wait();
	  turnStileA->Signal();
	}
	mutex->Signal();
	turnStileA->Wait();
	turnStileA->Signal();
}
/*!
  finalTurnstile stands as the final block, and once released indicates that all threads have successfully executed the code, and the firstTurnstile has been reset
 */
void Barrier::finalTurnstile(){	
	mutex->Wait();
	count--;
	if(count == 0){
	  turnStileA->Wait();
	  turnStileB->Signal();
	}
	mutex->Signal();
	turnStileB->Wait();
	turnStileB->Signal();
}

void Barrier::Wait(){
  	firstTurnstile();
        finalTurnstile();
}

Barrier::Barrier(int count){
          n = count;//set sentinel number for both turnstiles
	  this->count = 0;
	  // ref : en.cppreference.com/w/cpp/memory/shared_ptr/make_shared
	  mutex=std::make_shared<Semaphore>(1);
	  turnStileA=std::make_shared<Semaphore>(0);
	  turnStileB=std::make_shared<Semaphore>(1);
	  
}
=======
  FirstPhase is called to indicate that the thread has reached the first turnstile or rendezvous
 */
void Barrier::FirstPhase(){
  	mutex->Wait();
	count++;
	if(count == n){
	  barrierB->Wait();
	  barrierA->Signal();
	}
	mutex->Signal();
	barrierA->Wait();
	barrierA->Signal();
}
/*!
  Second phase is called to indicate that all the threads have executed there code and the rendezvous or turnstile is reset and ready to use again
 */
void Barrier::SecondPhase(){	
	mutex->Wait();
	count--;
	if(count == 0){
	  barrierA->Wait();
	  barrierB->Signal();
	}
	mutex->Signal();
	barrierB->Wait();
	barrierB->Signal();
}

void Barrier::Wait(){
  	FirstPhase();
  	SecondPhase();
}

Barrier::Barrier(int count){
	  n = count;
	  this->count = 0;
	  mutex=std::make_shared<Semaphore>(1);
	  barrierA=std::make_shared<Semaphore>(0);
	  barrierB=std::make_shared<Semaphore>(1);
	  
}

>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
