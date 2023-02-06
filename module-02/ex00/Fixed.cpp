#include "Fixed.hpp"

Fixed::Fixed(void) {
  this->_fixedPointNumber = 0;
}

Fixed& Fixed::operator = (const Fixed& instance){
    this->_fixedPointNumber = instance._fixedPointNumber;
    return (*this);
}

Fixed::Fixed(const Fixed& instance) {
  if (this != &instance) {
    *this = instance;
  }
  else{
    std::cout << "Cannot assign duplicated instances!" << std::endl;
  }
}