/**
 * @author Douglas De Rizzo Meneghetti (douglasrizzom@gmail.com)
 * @date   2017-6-14
 * @brief  Base class for all data structures
 */


#ifndef AULA1_DATASTRUCTURE_HPP
#define AULA1_DATASTRUCTURE_HPP

#include <string>

//! Base class for all data structures.
//! Contains methods that all other data structures must implement.
class DataStructure {
 public:
  //! Outputs the number of elements stored in the structure
  //! \return number of elements stored in the structure
  virtual int getSize()=0;

  //! Provides the name of the data structure as a string representation
  //! \return name of the data structure
  virtual std::string getName()=0;

  //! Check whether the structure is empty
  //! \return True if empty, otherwise false
  virtual bool isEmpty()=0;

  //! Check whether the structure is full
  //! \return True if full, otherwise false
  virtual bool isFull()=0;
};

#endif
