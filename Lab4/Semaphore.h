<<<<<<< HEAD
/**
 * Author: Jake Murphy Smith
 * Date:   26-03-2018
 * Filename: Semaphore.h
 * Last modified by:   Jake Murphy Smith
 * Last modified time: 26-03-2018
 * License: GNU GENERAL PUBLIC LICENSE
 */

#include <mutex>
#include <condition_variable>

/*!
 *  \class Semaphore
 *  \brief Semaphore implementation
 *
 *  Using mutex_counter, the_mutex and mutex_condition variable
 */
class Semaphore{

private:
  int mutex_counter; /*! < Semaphore counter */
  std::mutex the_mutex; /*! < Mutex variable */
  std::condition_variable mutex_condition; /*! < Condition variable */

 public:
  Semaphore(int count=0): mutex_counter(count){};
  void Wait();
  void Signal();
=======
#include <mutex>
#include <condition_variable>
#include <chrono>
/*! \class Semaphore
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore

*/
class Semaphore
{
private:
    unsigned int m_uiCount; /*!< Holds the Semaphore count */
    std::mutex m_mutex;
    std::condition_variable m_condition;

public:
    Semaphore(unsigned int uiCount=0)
          : m_uiCount(uiCount) { };
    void Wait();
    template< typename R,typename P >
    bool Wait(const std::chrono::duration<R,P>& crRelTime);
    void Signal();

>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
};
