#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  // constructors
  WrongCat(void);
  // copy constructor
  WrongCat(const WrongCat& copy);
  // destructors
  ~WrongCat(void);
  // copy assignment operator
  WrongCat& operator=(const WrongCat& copy);
  // polymorphism
  void makeSound(void) const;
};

#endif
