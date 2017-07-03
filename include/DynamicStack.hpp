/**
 * @author Douglas De Rizzo Meneghetti (douglasrizzom@gmail.com)
 * @date   2017-6-14
 * @brief  Stack implementation with dynamic memory allocation
 */

#ifndef AULA1_DYNAMICSTACK_HPP
#define AULA1_DYNAMICSTACK_HPP

#include <stdexcept>
#include <iostream>
#include "Stack.hpp"
#include "ProtectedLinkedList.hpp"

//! Stack implementation with dynamic memory allocation.
//! This stack extends a ProtectedLinkedList in order to gain dynamic memory allocation powers.
//! \tparam T The type of object the data structure will contain
template<class T>
class DynamicStack : public ProtectedLinkedList<T>, public Stack<T> {
 public:
  explicit DynamicStack() {}

  //! create the structure and populate it with the data from the array
  //! \param data an array with data with which the structure will be initialized
  explicit DynamicStack(T data[]) : ProtectedLinkedList<T>(data) {}

  std::string getName() { return "Dynamic Stack"; }

  void push(T val) { ProtectedLinkedList<T>::insert(val, getSize()); }

  T pop() {
    if (isEmpty())
      throw std::out_of_range("The stack is empty");
    return ProtectedLinkedList<T>::remove(getSize() - 1);
  }

  T peek() {
    if (isEmpty())
      throw std::out_of_range("The stack is empty");
    return ProtectedLinkedList<T>::get(getSize() - 1);
  }

  int getSize() { return ProtectedLinkedList<T>::getSize(); }

  bool isEmpty() { return ProtectedLinkedList<T>::isEmpty(); }

  bool isFull() { return ProtectedLinkedList<T>::isFull(); }
};

#endif