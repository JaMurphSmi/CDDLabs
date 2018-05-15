/**
 * Author: Jake Murphy Smith
 * Date:   26-03-2018
 * Filename: Barrier.cpp
 * Last modified by:   Jake Murphy Smith
 * Last modified time: 26-03-2018
 * License: GNU GENERAL PUBLIC LICENSE
 */

#include "Barrier.h"
#include <iostream>
#include <mutex>
/*!
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

