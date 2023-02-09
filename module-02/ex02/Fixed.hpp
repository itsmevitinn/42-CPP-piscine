#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
 private:
  int _fixedPointNumber;
  static const int _bits = 8;

 public:
  // constructors and destructors
  Fixed(void);
  Fixed(const int number);
  Fixed(const float number);
  Fixed(const Fixed& instance);
  ~Fixed(void);

  // member functions
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  // assignment operator
  Fixed& operator=(const Fixed& afterOperator);

  // comparison operators
  bool operator>(const Fixed& afterOperator);
  bool operator<(const Fixed& afterOperator);
  bool operator>=(const Fixed& afterOperator);
  bool operator<=(const Fixed& afterOperator);
  bool operator==(const Fixed& afterOperator);
  bool operator!=(const Fixed& afterOperator);

  // arithmetic operators
  Fixed& operator+(const Fixed& afterOperator);
  Fixed& operator-(const Fixed& afterOperator);
  Fixed& operator*(const Fixed& afterOperator);
  Fixed& operator/(const Fixed& afterOperator);

  // increment/decrement operators
  Fixed& operator++(void);
  Fixed& operator--(void);
  Fixed operator--(int);
  Fixed operator++(int);

  // static member functions
  static const Fixed& max(const Fixed& first, const Fixed& second);
  static Fixed& max(Fixed& first, Fixed& second);
  static const Fixed& min(const Fixed& first, const Fixed& second);
  static Fixed& min(Fixed& first, Fixed& second);
};

std::ostream& operator<<(std::ostream& os, const Fixed& instance);

#endif
