/**
 * Author: Jake Murphy Smith
 * Date:   26-03-2018
 * Filename: Barrier.h
 * Last modified by:   Jake Murphy Smith
 * Last modified time: 26-03-2018
 * License: GNU GENERAL PUBLIC LICENSE
 */

#include <mutex>
#include "Semaphore.h"
/*!
<<<<<<< HEAD
  Implementation(finally working) of a rendezvous with more than two threads. N threads much reach a certain point in the code (rendezvous), being controlled by a turnstile at two positions, before continuing
=======
  Class used to implement a rendezvous with more than two threads, meaning N threads will have to reach a certain point (rendezvous) before continuing
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
 */
class Barrier{
public:
 	int count;
	int n;
	std::shared_ptr<Semaphore>  mutex;
	std::shared_ptr<Semaphore>  turnStileA;
	std::shared_ptr<Semaphore>  turnStileB;
	void Wait();
	void firstTurnstile();
	void finalTurnstile();
        Barrier(int count);
	
};
