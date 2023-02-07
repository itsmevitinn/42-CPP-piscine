#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 private:
  int _fixedPointNumber;
  static const int _bits = 8;

 public:
  Fixed(void);
  Fixed(const Fixed& instance);
  Fixed(const int int_nbr);
  Fixed(const float float_nbr);

  ~Fixed(void);

  Fixed& operator=(const Fixed& instance);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};

#endif
