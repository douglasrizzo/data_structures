/**
 * @author Douglas De Rizzo Meneghetti (douglasrizzom@gmail.com)
 * @date   2017-6-8
 * @brief  Doubly-linked list implementation with dynamic memory allocation
 */

#ifndef AULA1_LINKEDLIST_HPP
#define AULA1_LINKEDLIST_HPP

#include <iostream>
#include "ProtectedLinkedList.hpp"

//! Doubly-linked list implementation with dynamic memory allocation.
//! This class exposes many of the protected methods from ProtectedLinkedList, where all list-related functionality is actually implemented.
//! \tparam T The type of object the data structure will contain
template<class T>
class LinkedList : public ProtectedLinkedList<T> {
public:
    explicit LinkedList() {
    }

    //! create the structure and populate it with the data from the array
    //! \param data an array with data with which the structure will be initialized
    explicit LinkedList(T data[]) : ProtectedLinkedList<T>(data) {
    }

    string getName() { return "Linked List"; }

    //! Insert an element at the end of the list
    //! \param val the value to be inserted
    virtual void insert(T val) {
        ProtectedLinkedList<T>::insert(val);
    }

    //! Insert an element at the specified position in the list
    //! \param val the value to be inserted
    //! \param index position of the list that the element will be inserted on
    virtual void insert(T val, int index) {
        ProtectedLinkedList<T>::insert(val, index);
    }

    //! Remove an element from the list
    //! \param index position of the element to be removed
    //! \return the element that is being removed
    virtual T remove(int index) {
        return ProtectedLinkedList<T>::remove(index);
    }

    //! Get the element at the specified position in the list, without removing it
    //! \param index index of the desired element
    virtual T get(int index) {
        return ProtectedLinkedList<T>::get(index);
    }

    //! Creates an Iterator, an object that allows the sequential
    //! access of values in a Linked List without the search overhead
    //! \return an Iterator starting from the first node of the list
    Iterator<T> iterator() {
        return Iterator<T>(ProtectedLinkedList<T>::getFirst());
    }
};

#endif