#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <deque>

template <typename T>
typename T::iterator easyfind(T& container, int value);

class ValueNotFound : public std::exception {
 public:
  const char* what() const throw();
};

#include "easyfind.tpp"

#endif
