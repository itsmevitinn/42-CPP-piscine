#include "Array.hpp"

// constructors and destructors
template <typename T>
Array<T>::Array(void) : _array(new T[0]), _size(0) {
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
}

template <typename T>
Array<T>::Array(const Array& instance) {
  this->_size = instance._size;
  this->_array = new T[instance._size];
  for (unsigned int i = 0; i < instance._size; i++) {
    this->_array[i] = instance._array[i];
  }
}

template <typename T>
Array<T>::~Array(void) {
  delete[] this->_array;
}

// member functions
template <typename T>
size_t Array<T>::size(void) const {
  return (this->_size);
}

// operator overload
template <typename T>
T& Array<T>::operator[](unsigned int index) {
  if (index >= this->_size) {
    throw Array<T>::OutOfBoundsException();
  }
  return (this->_array[index]);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& instance) {
  if (this != &instance) {
    this->~Array();
    this->_size = instance._size;
    this->_array = new T[instance._size];
    for (unsigned int i = 0; i < instance._size; i++) {
      this->_array[i] = instance._array[i];
    }
  }
  return (*this);
}

// custom exceptions
template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
  return ("Index is out of bounds!");
}
