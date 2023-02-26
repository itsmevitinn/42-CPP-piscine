#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <cstdlib>
#include <iostream>
#include <limits>
class Scalar {
 private:
  std::string _charValue;
  int _intValue;
  float _floatValue;
  double _doubleValue;

 public:
  // constructors and destructors
  Scalar(void);
  Scalar(std::string string);
  ~Scalar(void);
  // copy constructors
  Scalar(const Scalar& instance);
  // copy assignment operator overload
  Scalar& operator=(const Scalar& instance);
  class InvalidInput : public std::exception {
   public:
    const char* what() const throw();
  };
  int isPseudoLiteral(std::string string);
  int isOverflow(std::string string);
  void printCharLiteral(char letter);
  void printInt(std::string string);
  void printChar(std::string string);
  void printFloat(std::string string);
  void printDouble(std::string string);
};
#endif
