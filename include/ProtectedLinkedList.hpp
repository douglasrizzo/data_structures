/**
 * @author Douglas De Rizzo Meneghetti (douglasrizzom@gmail.com)
 * @date   2017-6-14
 * @brief  Doubly-linked list implementation with dynamic memory allocation.
 */

#ifndef AULA1_PROTECTEDLINKEDLIST_HPP
#define AULA1_PROTECTEDLINKEDLIST_HPP

#include <string>
#include <stdexcept>
#include "Node.hpp"
#include "DataStructure.hpp"

using namespace std;

//! Doubly-linked list implementation with dynamic memory allocation.
//! Many methods in this class are protected so the class can be used as an extension for other data structures.
//! \tparam T The type of object the data structure will contain
template<class T>
class ProtectedLinkedList : public DataStructure {
private:
    Node<T> *first;
    Node<T> *last;
    int size = 0;

public:
    string getName() { return "Protected Linked List"; }

    ProtectedLinkedList() {
        first = last = NULL;
    }

    ~ProtectedLinkedList() {
        Node<T> *tmp;

        while (first != NULL) {
            tmp = first;
            first = first->getNext();
            delete tmp;
        }
        last = NULL;
        size = 0;
    }

protected:
    Node<T> *getNode(int index) {
        Node<T> *tmp;
        if (index <= size - index) {
            tmp = first;

            for (int i = 0; i < index - 1; i++)
                tmp = tmp->getNext();
        }
        else {
            tmp = last;

            for (int i = size - 1; i > index; i--)
                tmp = tmp->getPrevious();
        }
        return tmp;
    }

//! create the structure and populate it with the data from the array
//! \param data an array with data with which the structure will be initialized
    explicit ProtectedLinkedList(const T data[]) {
        for (int i = 0; i <= (sizeof(data) / sizeof(data[0])); i++) {
            insert(data[i]);
        }
    }

    Node<T> *getFirst() const {
        return first;
    }

    Node<T> *getLast() const {
        return last;
    }

    //! Insert an element at the end of the list
    //! \param val the value to be inserted
    virtual void insert(const T val) {
        ProtectedLinkedList::insert(val, size);
    }

    //! Insert an element at the specified position in the list
    //! \param val the value to be inserted
    //! \param index position of the list that the element will be inserted on
    virtual void insert(const T val, const int index) {
        if (index < 0)
            throw std::out_of_range("Negative index not allowed.");
        if (index > size)
            throw std::out_of_range("Nonexistent index.");

        // if it's the first element on the list, create the first node
        if (size == 0) {
            first = new Node<T>();
            first->setValue(val);

            // first and last both point to the same node at the beginning
            last = first;
        }
            // if the insertion is at the beginning,
            // use the pointer to the first node to
            // speed things up and replace first too
        else if (index == 0) {
            Node<T> *tmp = new Node<T>();
            tmp->setValue(val);
            tmp->setNext(first);
            first->setPrevious(tmp);
            first = tmp;
        }
            // the same applies when an insertion is made in the last node
            // this is useful for the stack and queue implementations
        else if (index == size) {
            last->setNext(new Node<T>());
            last->getNext()->setValue(val);
            last->getNext()->setPrevious(last);
            last = last->getNext();
        }
            // if the index is in the middle of the list, it must be traversed
        else {
            Node<T> *tmp = getNode(index);

            // a new node is created and put between
            // the current node and the next one
            Node<T> *tmp2 = new Node<T>();
            tmp2->setValue(val);
            tmp2->setNext(tmp->getNext());
            tmp2->setPrevious(tmp);
            tmp->getNext()->setPrevious(tmp2);
            tmp->setNext(tmp2);
        }
        size++;
    }

    //! Remove an element from the list
    //! \param index position of the element to be removed
    //! \return the element that is being removed
    virtual T remove(const int index) {
        if (index < 0)
            throw std::out_of_range("Negative index not allowed.");
        if (index >= size)
            throw std::out_of_range("Nonexistent index in list.");

        Node<T> *tmp = getNode(index);

        T ret = tmp->getValue();

        if (tmp->getPrevious() != NULL) {
            tmp->getPrevious()->setNext(tmp->getNext());
        }
        else {
            first = tmp->getNext();
        }

        if (tmp->getNext() != NULL) {
            tmp->getNext()->setPrevious(tmp->getPrevious());
        }
        else {
            last = tmp->getPrevious();
        }
        size--;

        tmp->setNext(NULL);
        tmp->setPrevious(NULL);
        delete tmp;

        return ret;
    }

    //! Get the element at the specified position in the list, without removing it
    //! \param index index of the desired element
    virtual T get(const int index) {
        if (index < 0)
            throw std::out_of_range("Negative index not allowed.");
        if (index > size)
            throw std::out_of_range("Nonexistent index.");

        Node<T> *tmp = getNode(index);
        return tmp->getValue();
    }

    //! Creates an Iterator, an object that allows the sequential
    //! access of values in a Linked List without the search overhead
    //! \return an Iterator starting from the first node of the list
    virtual Iterator<T> iterator() {
        return Iterator<T>(first);
    }

public:

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return false;
    }
};

#endif