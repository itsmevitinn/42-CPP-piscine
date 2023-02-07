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
  ~Fixed(void);
  Fixed& operator = (const Fixed& instance);
  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif
