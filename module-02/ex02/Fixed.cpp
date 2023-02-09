#include "Fixed.hpp"

//constructors/destructors
Fixed::Fixed(void) {
  this->_fixedPointNumber = 0;
}

Fixed::Fixed(const int number) {
  this->_fixedPointNumber = number << this->_bits;
}

Fixed::Fixed(const float number) {
  this->_fixedPointNumber = roundf(number * (1 << this->_bits));
}

Fixed::Fixed(const Fixed& instance) {
  if (this != &instance) {
    *this = instance;
  } else {
    std::cerr << "Cannot copy the same instance!" << std::endl;
  }
}

Fixed::~Fixed(void) {
}

//member functions
float Fixed::toFloat(void) const {
  return ((float)this->_fixedPointNumber / (float)(1 << this->_bits));
}

int Fixed::toInt(void) const {
  return ((int)this->_fixedPointNumber >> this->_bits);
}


int Fixed::getRawBits(void) const {
  return (this->_fixedPointNumber);
}

void Fixed::setRawBits(int const raw) {
  this->_fixedPointNumber = raw;
}

//assignment operator
Fixed& Fixed::operator=(const Fixed& instance) {
  this->_fixedPointNumber = instance._fixedPointNumber;
  return (*this);
}

// comparison operators
bool Fixed::operator>(const Fixed& afterOperator) {
  if (this->getRawBits() > afterOperator.getRawBits())
    return (1);
  else {
    return (0);
  }
}

bool Fixed::operator<(const Fixed& afterOperator) {
  if (this->getRawBits() < afterOperator.getRawBits())
    return (1);
  else {
    return (0);
  }
}

bool Fixed::operator>=(const Fixed& afterOperator) {
  if (this->getRawBits() >= afterOperator.getRawBits())
    return (1);
  else {
    return (0);
  }
}

bool Fixed::operator<=(const Fixed& afterOperator) {
  if (this->getRawBits() <= afterOperator.getRawBits())
    return (1);
  else {
    return (0);
  }
}

bool Fixed::operator==(const Fixed& afterOperator) {
  if (this->getRawBits() == afterOperator.getRawBits())
    return (1);
  else {
    return (0);
  }
}

bool Fixed::operator!=(const Fixed& afterOperator) {
  if (this->getRawBits() != afterOperator.getRawBits())
    return (1);
  else {
    return (0);
  }
}

//arithmetic operators
Fixed& Fixed::operator+(const Fixed& afterOperator) {
  this->_fixedPointNumber = this->getRawBits() + afterOperator.getRawBits();
  return (*this);
}

Fixed& Fixed::operator-(const Fixed& afterOperator) {
  this->_fixedPointNumber = this->getRawBits() - afterOperator.getRawBits();
  return (*this);
}

Fixed& Fixed::operator*(const Fixed& afterOperator) {
  // dividimos o resultado por 256 (right shift de 8 bits) p/ o operador << conseguir printar esse resultado como float corretamente
  this->_fixedPointNumber = (this->getRawBits() * afterOperator.getRawBits() >> this->_bits);
  return (*this);
}

Fixed& Fixed::operator/(const Fixed& afterOperator) {
  // multiplicamos o resultado por 256 (ligar o primeiro bit da esquerda) p/ o operador << conseguir printar esse resultado como float corretamente
  this->_fixedPointNumber = (this->getRawBits() / afterOperator.getRawBits() * (1 << this->_bits));
  return (*this);
}

//increment/decrement operators
Fixed& Fixed::operator++(void) {
  ++this->_fixedPointNumber;
  return (*this);
}

Fixed Fixed::operator++(int) {
  Fixed temp = *this;
  ++this->_fixedPointNumber;
  return (temp);
}

Fixed Fixed::operator--(int) {
  Fixed temp = *this;
  --this->_fixedPointNumber;
  return (temp);
}

Fixed& Fixed::operator--(void) {
  --this->_fixedPointNumber;
  return (*this);
}

// static member functions
const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
  if (first.getRawBits() > second.getRawBits())
    return (first);
  return (second);
}

Fixed& Fixed::max(Fixed& first, Fixed& second) {
  if (first > second)
    return (first);
  return (second);
}
const Fixed& Fixed::min(const Fixed& first, const Fixed& second) {
  if (first.getRawBits() < second.getRawBits())
    return (first);
  return (second);
}

Fixed& Fixed::min(Fixed& first, Fixed& second) {
  if (first < second)
    return (first);
  return (second);
}

// global overloaded operators (Need include)
std::ostream& operator<<(std::ostream& os, const Fixed& instance) {
  os << instance.toFloat();
  return (os);
}
