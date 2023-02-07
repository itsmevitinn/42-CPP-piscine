#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
 private:
  int _fixedPointNumber;
  static const int _bits = 8;

 public:
  Fixed(void);
  Fixed(const int number);
  Fixed(const float number);
  Fixed(const Fixed& instance);
  ~Fixed(void);

  Fixed& operator=(const Fixed& instance);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& instance);

#endif
