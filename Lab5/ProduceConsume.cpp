/**
 * Author: Jake Murphy Smith
 * Date:   26-03-2018
 * Filename: ProduceConsume.cpp
 * Last modified by:   Jake Murphy Smith
 * Last modified time: 26-03-2018
 * License: GNU GENERAL PUBLIC LICENSE
 */

#include "ProduceConsume.h"

//Constructor
ProduceConsume::ProduceConsume(int bufferSize){
  theBufferSize = bufferSize;//Defining the size of the buffer
  bufferFree = std::make_shared<Semaphore>(bufferSize);
  bufferLock = std::make_shared<Semaphore>(1);
  bufferHeld = std::make_shared<Semaphore>(0);
}

void ProduceConsume::enqueue(char charForBuffer){
  bufferFree->Wait();
  bufferLock->Wait();
  buffer.push(charForBuffer);
  bufferLock->Signal();
  bufferHeld->Signal();
}

char ProduceConsume::dequeue(){
  bufferHeld->Wait();
  bufferLock->Wait();
  char charFromBuffer = buffer.front();
  buffer.pop();
  bufferLock->Signal();
  bufferFree->Signal();
  return charFromBuffer;
}
