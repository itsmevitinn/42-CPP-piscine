#include "Fixed.hpp"

Fixed::Fixed(void) {
  std::cout << "Default constructor called" << std::endl;
  this->_fixedPointNumber = 0;
}

Fixed& Fixed::operator=(const Fixed& instance) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->_fixedPointNumber = instance._fixedPointNumber;
  return (*this);
}

Fixed::Fixed(const Fixed& instance) {
  std::cout << "Copy constructor called" << std::endl;
  if (this != &instance) {
    *this = instance;
  } else {
    std::cout << "Cannot assign duplicated instances!" << std::endl;
  }
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (this->_fixedPointNumber);
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->_fixedPointNumber = raw;
}
