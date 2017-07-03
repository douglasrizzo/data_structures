/**
 * @author Douglas De Rizzo Meneghetti (douglasrizzom@gmail.com)
 * @date   2017-6-14
 * @brief  Abstract stack interface
 */

#ifndef AULA1_STACK_HPP
#define AULA1_STACK_HPP

#include <string>
#include "DataStructure.hpp"

//! Abstract stack interface.
//! \tparam T The type of object the data structure will contain
template<class T>
class Stack : public DataStructure {
 public:

  std::string getName() { return "Stack Interface"; }

  //! Add an element to the top of the stack
  //! \param val the value to be added to the stack
  virtual void push(T val) =0;

  //! Remove an element from the top of the stack
  //! \return the value that is being removed
  virtual T pop() =0;

  //! See the value from the top of the stack, without removing it
  //! \return The value on the top of the stack
  virtual T peek() =0;
};

#endif