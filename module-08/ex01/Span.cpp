#include "Span.hpp"

Span::Span(unsigned int size) : _size(size) {
}

Span::~Span(void) {
}

Span::Span(const Span& instance) : _array(instance._array), _size(instance._size) {
}

Span& Span::operator=(const Span& instance) {
  if (this != &instance) {
    this->_array = instance._array;
    this->_size = instance._size;
  }
  return (*this);
}

// member functions
void Span::addNumber(int number) {
  if (this->_array.size() < this->_size)
    this->_array.push_back(number);
  else
    throw Span::FullVector();
}

void Span::addNumber(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end) {
  // how many numbers exists between begin and end
  int numbersQty = std::distance(begin, end);
  if ((numbersQty + this->_array.size()) > this->_size)
    throw Span::FullVector();
  // inserts from end of the array, values between begin and end;
  this->_array.insert(this->_array.end(), begin, end);
}

int Span::shortestSpan(void) const {
  if (this->_array.size() <= 1)
    throw Span::InvalidVector();
  // creating vector with the same size as our _array and filling with 0 values
  std::vector<int> differences(this->_array.size(), 0);
  std::adjacent_difference(this->_array.begin(), this->_array.end(), differences.begin());
  std::vector<int>::iterator current;
  for (current = differences.begin(); current != differences.end(); ++current) {
    // getting the abs value because distance between values is always positive
    *current = std::abs(*current);
  }
  // begin + 1 because the adjacent_difference do the differences between numbers from the [1] index;
  return (*(std::min_element(differences.begin() + 1, differences.end())));
}

int Span::longestSpan(void) const {
  if (this->_array.size() <= 1)
    throw Span::InvalidVector();
  // creating vector with the same size as our _array and filling with 0 values
  std::vector<int> differences(this->_array.size(), 0);
  std::adjacent_difference(this->_array.begin(), this->_array.end(), differences.begin());
  std::vector<int>::iterator current;
  for (current = differences.begin(); current != differences.end(); ++current) {
    // getting the abs value because distance between values must be always positive
    *current = std::abs(*current);
  }
  // begin + 1 because the adjacent_difference calculate (next - previous) and store result from the [1] index;
  return (*(std::max_element(differences.begin() + 1, differences.end())));
}

// custom exceptions
const char* Span::FullVector::what() const throw() {
  return ("Vector is full!");
}

const char* Span::InvalidVector::what() const throw() {
  return ("Can't find span because vector is empty or has only a single value!");
}
