/**
 * @author Douglas De Rizzo Meneghetti (douglasrizzom@gmail.com)
 * @date   2017-6-14
 * @brief  Queue implementation using a native C++ array as data storage.
 */

#ifndef AULA1_STATICQUEUE_HPP
#define AULA1_STATICQUEUE_HPP

#include <stdexcept>
#include <string>
#include "Queue.hpp"

//! Queue implementation using a native C++ array as data storage.
//! \tparam T The type of object the data structure will contain
template<class T>
class StaticQueue : public Queue<T> {
 private:
  int size, head, tail, count;
  T *data;

 public:
  std::string getName() { return "Static Queue"; }

  //! Create a fixed-size queue
  //! \param size the size of the queue
  explicit StaticQueue(int size) {
    head = tail = count = 0;
    this->size = size;
    data = new T[size];
  }

  //! create the structure and populate it with the data from the array
  //! \param data an array with data with which the structure will be initialized
  explicit StaticQueue(T data[]) {
    this->data = data;

    size = count = (sizeof(data) / sizeof(data[0])) + 1;
    head = 0;
    tail = (sizeof(data) / sizeof(data[0]));
  }

  ~StaticQueue() { delete[] data; }

  void enqueue(T val) {
    if (isFull()) {
      throw std::out_of_range("The queue is full.");
    }

    data[tail] = val;
    count ++;
    tail = (tail + 1) % size;
  }

  T dequeue() {
    if (isEmpty())
      throw std::out_of_range("The queue is empty.");

    T tmp = data[head];
    count --;
    head = (head + 1) % size;

    return tmp;
  }

  T peek() {
    if (isEmpty())
      throw std::out_of_range("The queue is empty.");
    return data[head];
  }

  int getSize() { return count; }

  bool isEmpty() { return count == 0; }

  bool isFull() { return count == size; }
};

#endif
