//
// Created by dodo on 15/06/17.
//

#ifndef AULA1_ORDEREDLIST_HPP
#define AULA1_ORDEREDLIST_HPP

#include "LinkedList.hpp"

//! Doubly-linked ordered list implementation with dynamic memory allocation.
//! This classes searches for the appropriate place to insert an element
//! keeping the array sorted ata ll times, much like insertion sort.
//! \tparam T The type of object the data structure will contain
template<class T>
class OrderedList : public LinkedList<T> {
public:
    string getName() { return "Ordered List"; }

    explicit OrderedList() {}

    //! create the structure and populate it with the data from the array
    //! \param data an array with data with which the structure will be initialized
    explicit OrderedList(const T data[])  {
        for (int i = 0; i <= (sizeof(data) / sizeof(data[0])); i++) {
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
            while (tmp != NULL && tmp->getValue() < val) {
                index++;
                tmp = tmp->getNext();
            }
            LinkedList<T>::insert(val, index);
        }
    }

    void insert(T val, int index) {
        insert(val);
    }

    T remove(int index) {
        return LinkedList<T>::remove(index);
    }

    T get(int index) {
        return LinkedList<T>::get(index);
    }
};

#endif