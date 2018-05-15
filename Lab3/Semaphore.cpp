/**
 * Author: Jake Murphy Smith
 * Date:   26-03-2018
 * Filename: Semaphore.cpp
 * Last modified by:   Jake Murphy Smith
 * Last modified time: 26-03-2018
 * License: GNU GENERAL PUBLIC LICENSE
 */

#include "Semaphore.h"
#include <iostream>

/*!
 * \class Semaphore
 * \brief Using exploration of Signal and Wait using the 
 * \variables the_mutex, mutex_condition, and mutex_counter
*/


//! Semaphore Wait method locks the thread and decrement counter
void Semaphore::Wait(){
  std::unique_lock< std::mutex > lock(the_mutex);
  mutex_condition.wait(lock, [&]()-> bool {return mutex_counter > 0 ;});
  --mutex_counter;
};

//! Semaphore Signal method incremet counter and release one thread
void Semaphore::Signal(){
  std::unique_lock< std::mutex > lock(the_mutex);
  mutex_counter++;
  mutex_condition.notify_one();
};
