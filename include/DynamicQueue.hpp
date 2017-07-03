/**
 * @author Douglas De Rizzo Meneghetti (douglasrizzom@gmail.com)
 * @date   2017-6-14
 * @brief  Queue implementation with dynamic memory allocation
 */
#ifndef AULA1_DYNAMICQUEUE_HPP
#define AULA1_DYNAMICQUEUE_HPP

#include <stdexcept>
#include <iostream>
#include "Queue.hpp"
#include "ProtectedLinkedList.hpp"

//! Queue implementation with dynamic memory allocation.
//! This queue extends a ProtectedLinkedList in order to gain dynamic memory allocation powers.
//! \tparam T The type of object the data structure will contain
template<class T>
class DynamicQueue : public ProtectedLinkedList<T>, public Queue<T> {
 public:
  string getName() { return "Dynamic Queue"; }

  explicit DynamicQueue() {}

  //! create the structure and populate it with the data from the array
  //! \param data an array with data with which the structure will be initialized
  explicit DynamicQueue(int data[]) : ProtectedLinkedList<T>(data) {}

  void enqueue(T val) {
    ProtectedLinkedList<T>::insert(val, ProtectedLinkedList<T>::getSize());
  }

  T dequeue() {
    if (isEmpty())
      throw std::out_of_range("The queue is empty");
    return ProtectedLinkedList<T>::remove(0);
  }

  T peek() {
    if (isEmpty())
      throw std::out_of_range("The queue is empty");
    return ProtectedLinkedList<T>::get(0);
  }

  int getSize() { return ProtectedLinkedList<T>::getSize(); }

  bool isEmpty() { return ProtectedLinkedList<T>::isEmpty(); }

  bool isFull() { return ProtectedLinkedList<T>::isFull(); }
};

#endif