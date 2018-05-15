/**
<<<<<<< HEAD
 * Author: Jake Murphy Smith
 * Date:   26-03-2018
 * Filename: Semaphore.h
 * Last modified by:   Jake Murphy Smith
 * Last modified time: 26-03-2018
 * License: GNU GENERAL PUBLIC LICENSE
 */

=======
 * @Author: Jake Murphy Smith
 * @License: GNU GENERAL PUBLIC LICENSE
 */



>>>>>>> 33dd8c88ace74443717560760d87d652b15be9f3
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
};
