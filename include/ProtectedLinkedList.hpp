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
        delete first;
    }

    //! String representation of the data structure
    //! \return a string representation of the data structure
    string to_string() {
        string retorno;
        Node<T> *tmp = getFirst();
        for (int i = 0; i < size; i++) {
            retorno.append(std::to_string(tmp->getValue())).append(" ");
            tmp = tmp->getNext();
        }
        retorno.append("\n");
        return retorno;
    }

protected:
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
    virtual void insert(const T &val) {
        ProtectedLinkedList::insert(val, size);
    }

    //! Insert an element at the specified position in the list
    //! \param val the value to be inserted
    //! \param index position of the list that the element will be inserted on
    virtual void insert(const T &val, const int index) {
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
            Node<T> *tmp = first;

            for (int i = 0; i < index - 1; i++)
                tmp = tmp->getNext();

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

        Node<T> *tmp = first;
        for (int i = 0; i < index; i++)
            tmp = tmp->getNext();

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

        Node<T> *tmp = first;

        for (int i = 0; i < index; i++)
            tmp = tmp->getNext();

        T ret = tmp->getValue();

        return ret;
    }

    //! Get the index where the specified element is in the list.
    //! \param val value to be found in the list
    virtual int getIndex(T &val) {
        Node<T> *tmp = first;

        for (int i = 0; i < getSize(); i++) {
            // this if part needs a hack because template
            // variables can be either pointers or objects
            T other = tmp->getValue();

            if (val == other || is_pointer<T>::value && &val == &other) {
                // additionally, for some reason
                // this if statement wasn't working
                // unless I created variables
                // instead of using reference directly, so...
                return i;
            }
            else if (val == other)
                return i;

            tmp = tmp->getNext();
        }

        return NULL;
    }

    virtual bool contains(T &val) {
        return getIndex(val) != NULL;
    }

public:

    int getSize() { return size; }

    bool isEmpty() { return size == 0; }

    bool isFull() { return false; }
};

#endif