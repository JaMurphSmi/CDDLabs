/**
 * Author: Jake Murphy Smith
 * Date:   26-03-2018
 * Filename: ProdConsumeMain.cpp
 * Last modified by:   Jake Murphy Smith
 * Last modified time: 26-03-2018
 * License: GNU GENERAL PUBLIC LICENSE
 */

#include "ProduceConsume.h"
#include <iostream>
#include <vector>
#include <thread>


void produceData(std::shared_ptr<ProduceConsume> pCBuffer, char theChar){
  pCBuffer->enqueue(theChar);
  std::cout << theChar << " : Produced\n";
}

void consumeData(std::shared_ptr<ProduceConsume> pCBuffer){
  std::cout << static_cast<char>(pCBuffer->dequeue()) << " : Consumed\n";
}

int main(void){
  // new object with size 20
  std::shared_ptr<ProduceConsume> pCBuffer(new ProduceConsume(20));
  std::thread thread1;
  std::thread thread2;
  std::vector<char> charPool;//char vector to hold data for buffer

  for(int i = 65; i < 91; ++i){
    charPool.push_back(static_cast<char>(i));//add chars A-Z
  }

  for(int i = 0; i < charPool.size(); ++i){
    thread1 = std::thread(produceData, pCBuffer, charPool[i]);
    thread2 = std::thread(consumeData, pCBuffer);

    // pause threads, iterate again until satisfied
    thread1.join();
    thread2.join();
  }

  /*!for(int i = 0; i < charPool.size(); ++i) {
    thread1 = std::thread(produceData, pCBuffer, charPool[i]);

    thread1.join();
   }
   for(int i = 0; i < charPool.size(); ++i) {
     thread2 = std::thread(consumeData, pCBuffer);

     thread2.join();
   }
  */
  return 0;
}
