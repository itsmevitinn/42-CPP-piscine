#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
 private:
  T* _array;
  unsigned int _size;

 public:
  // constructor and destructor
  Array(void);
  Array(unsigned int n);
  Array(const Array& instance);
  ~Array(void);
  // member function
  size_t size(void) const;
  // operator overload
  Array& operator=(const Array& instance);
  T& operator[](unsigned int index);
  // custom exception
  class OutOfBoundsException : public std::exception {
   public:
    const char* what() const throw();
  };
};

#include "Array.tpp"

#endif
