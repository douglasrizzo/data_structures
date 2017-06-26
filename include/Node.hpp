/**
 * @author Douglas De Rizzo Meneghetti (douglasrizzom@gmail.com)
 * @date   2017-6-8
 * @brief  Node used inside other data structures
 */

#ifndef AULA1_NODE_HPP
#define AULA1_NODE_HPP

#include <stddef.h>

//! Node used inside other data structures. Uses templates to allow storing any kind of object.
//! \tparam T the type of object the node will store.
template<class T>
class Node {
private:
    T value;
    Node *next;
    Node *previous;
public:

    Node() {
        next = previous = NULL;
    }

    ~Node() {
//        delete next;
//        delete previous;
    }

    T getValue() const {
        return value;
    }

    void setValue(T value) {
        this->value = value;
    }

    Node *getNext() const {
        return next;
    }

    void setNext(Node *next) {
        this->next = next;
    }

    Node *getPrevious() const {
        return previous;
    }

    void setPrevious(Node *previous) {
        this->previous = previous;
    }
};

#endif