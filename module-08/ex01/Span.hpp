#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

class Span {
 private:
  std::vector<int> _array;
  unsigned int _size;

 public:
  // constructors and destructors
  Span(unsigned int size);
  ~Span(void);
  // copy constructors
  Span(const Span& instance);
  // copy assignment operator overload
  Span& operator=(const Span& instance);
  // member functions
  void addNumber(int number);
  void addNumber(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end);
  int shortestSpan(void) const;
  int longestSpan(void) const;
  class FullVector : public std::exception {
   public:
    const char* what() const throw();
  };
  class InvalidVector : public std::exception {
   public:
    const char* what() const throw();
  };
};

#endif
