/**
 * @author Douglas De Rizzo Meneghetti (douglasrizzom@gmail.com)
 * @date   2017-6-14
 * @brief  Stack implementation using a native C++ array as data storage.
 */

#ifndef AULA1_STATICSTACK_HPP
#define AULA1_STATICSTACK_HPP

#include <stdexcept>
#include <string>
#include "Stack.hpp"

//! Stack implementation using a native C++ array as data storage.
//! \tparam T The type of object the data structure will contain
template<class T>
class StaticStack : public Stack<T> {
 private:
  int top, size;
  T *data;

 public:
  std::string getName() { return "Static Stack"; }

  //! Create a fixed-size stack
  //! \param size the size of the stack
  explicit StaticStack(int size) {
    this->size = size;
    top = -1;
    data = new T[size];
  }

  //! create the structure and populate it with the data from the array
  //! \param data an array with data with which the structure will be initialized
  explicit StaticStack(T data[]) : this->data(data) {
    top = sizeof(data)/sizeof(data[0]);
  }

  ~StaticStack() { delete[]data; }

  void push(T val) {
    if (isFull())
      throw std::out_of_range("The stack is full.");
    data[++top] = val;
  }

  T pop() {
    if (isEmpty())
      throw std::out_of_range("The stack is empty.");
    return data[top--];
  }

  T peek() {
    if (isEmpty())
      throw std::out_of_range("The stack is empty.");
    return data[top];
  }

  int getSize() {
    return top + 1;
  }

  bool isEmpty() {
    return top==-1;
  }

  bool isFull() {
    return top==size - 1;
  }
};

#endif
