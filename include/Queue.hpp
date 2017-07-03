/**
 * @author Douglas De Rizzo Meneghetti (douglasrizzom@gmail.com)
 * @date   2017-6-14
 * @brief  Abstract queue interface
 */

#ifndef AULA1_QUEUE_HPP
#define AULA1_QUEUE_HPP

#include <string>
#include "DataStructure.hpp"

//! Abstract queue interface
//! \tparam T The type of object the data structure will contain
template<class T>
class Queue : public DataStructure {
 public:

  std::string getName() { return "Queue Interface"; }

  //! Add an element to the end of the queue
  //! \param val the value to be added to the queue
  virtual void enqueue(T val) =0;

  //! Remove an element from the queue
  //! \return the value that is being removed
  virtual T dequeue()=0;

  //! See the first value from the queue, without removing it
  //! \return The first value on the queue
  virtual T peek() =0;
};

#endif