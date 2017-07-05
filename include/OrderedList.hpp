//
// Created by dodo on 15/06/17.
//

#ifndef AULA1_ORDEREDLIST_HPP
#define AULA1_ORDEREDLIST_HPP

#include "LinkedList.hpp"
#include <type_traits>
#include <functional>

//! Doubly-linked ordered list implementation with dynamic memory allocation.
//! This class searches for the appropriate place to insert an element
//! keeping the array sorted ata ll times, much like insertion sort.
//! \tparam T The type of object the data structure will contain
template<class T>
class OrderedList : public LinkedList<T> {
 private:
  function<int(T, T)> compare;

 public:
  string getName() { return "Ordered List"; }

  /*!
     \brief Creates the structure
     \param compareFunc a C++ 11 compliant function parameter that allows comparation between template objects
  */
  explicit OrderedList(std::function<int(T, T)> compareFunc) : compare(compareFunc) {
  }

  //! create the structure and populate it with the data from the array
  //! \param data an array with data with which the structure will be initialized
  //! \param compareFunc a C++ 11 compliant function parameter that allows comparation between template objects
  explicit OrderedList(const T data[], std::function<int(T, T)> compareFunc) : compare(compareFunc) {
    for (int i = 0; i <= (sizeof(data) / sizeof(data[0])); i ++) {
      // use this class implementation of insert() to ensure order
      insert(data[i]);
    }
  }

  //! Insert an element at its position on the list
  //! \param val the value to be inserted
  void insert(T val) {
    if (LinkedList<T>::isEmpty()) {
      LinkedList<T>::insert(val);
    }
    else {
      Node<T> *tmp = LinkedList<T>::getFirst();
      int index = 0;
      while (tmp != NULL && compare(val, tmp->getValue()) < 0) {
        index ++;
        tmp = tmp->getNext();
      }
      LinkedList<T>::insert(val, index);
    }
  }

  void insert(T val, int index) {
    insert(val);
  }

  //! Finds an element in the ordered list and returns its index.
  //! \param val the element to be found
  //! \return The index of the first element where compareFunc(val, element) == 0
  int indexOf(T val) {
    Node<T> *tmp = LinkedList<T>::getFirst();
    int index = 0;
    while (tmp != NULL && compare(val, tmp->getValue()) >= 0) {
      if (compare(val, tmp->getValue()) == 0)
        return index;
      index ++;
      tmp = tmp->getNext();
    }

    return - 1;
  }

  //! Answers whether the ordered list contains an enemy.
  //! \param val the element to be found
  //! \return true if there is at least one element where compareFunc(val, element) == 0, otherwise false
  bool contains(T val) {
    return indexOf(val) != - 1;
  }

  T remove(int index) {
    return LinkedList<T>::remove(index);
  }

  T get(int index) {
    return LinkedList<T>::get(index);
  }
};

#endif
