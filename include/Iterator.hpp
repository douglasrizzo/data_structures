/**
 * @author Douglas De Rizzo Meneghetti (douglasrizzom@gmail.com)
 * @date   2017-7-5
 * @brief  Object that provides iterative powers to classes composed of Node
 */

#ifndef AULA1_ITERATOR_HPP
#define AULA1_ITERATOR_HPP

//! This object provides iterative powers to classes that have Node as their
// underlying data storage objects.
//! \tparam T The type of object the Node inside the Iterator will hold.
template<class T>
class Iterator {
 private:

  Node <T> *node;
  bool firstRun = true;

 public:

  //! Creates an iterator.
  //! \param n The starting node for the iteration
  explicit Iterator(Node <T> *n) {
    node = n;
  }

  //! Returns whether the iterator has a next value to explore.
  //! \return True if there is a next value, otherwise false
  bool hasNext() {
    return firstRun and node != NULL or node->getNext() != NULL;
  }

  //! Returns whether the iterator has a previous value to explore.
  //! \return True if there is a previous value, otherwise false
  bool hasPrevious() {
    return node->getPrevious() != NULL;
  }

  //! Go to the next value.
  //! \return The next value in the iteration
  T next() {
    if (firstRun) {
      firstRun = ! firstRun;
      return node->getValue();
    }

    node = node->getNext();
    return node->getValue();
  }

  //! Go to the previous value.
  //! \return The previous value in the iteration
  T previous() {
    node = node->getNext();
    return node->getValue();
  }

  //! Get the current value the iterator holds.
  //! \return The current value in the iteration
  T current() {
    return node->getValue();
  }
};

#endif //AULA1_ITERATOR_HPP
