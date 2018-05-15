/**
 * Author: Jake Murphy Smith
 * Date:   26-03-2018
 * Filename: ProduceConsume.h
 * Last modified by:   Jake Murphy Smith
 * Last modified time: 26-03-2018
 * License: GNU GENERAL PUBLIC LICENSE
 */

#include "Semaphore.h"
#include <iostream>
#include <queue>

class ProduceConsume{

private:
  std::queue<char> buffer;//add to back, pop off front
  std::shared_ptr<Semaphore> bufferFree;
  std::shared_ptr<Semaphore> bufferLock;
  std::shared_ptr<Semaphore> bufferHeld;
  int theBufferSize;//sets the buffer size for the program

public:
  ProduceConsume();
  ProduceConsume(int buffSize);
  void enqueue(char charForBuffer);
  char dequeue();
};
