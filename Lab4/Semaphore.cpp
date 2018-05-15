<<<<<<< HEAD
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
=======
#include "Semaphore.h"
/*! \class Semaphore
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore

*/




void Semaphore::Wait()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount;
}

template< typename R,typename P >
bool Semaphore::Wait(const std::chrono::duration<R,P>& crRelTime)
{
      std::unique_lock< std::mutex > lock(m_mutex);
      if (!m_condition.wait_for(lock,crRelTime,[&]()->bool{ return m_uiCount>0; })){
	  return false;
      }
      --m_uiCount;
      return true;
}

void Semaphore::Signal()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}
>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
