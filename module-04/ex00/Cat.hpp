#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>

#include "Animal.hpp"

class Cat : public Animal {
 public:
  // constructors
  Cat(void);
  // copy constructor
  Cat(const Cat& copy);
  // destructors
  ~Cat(void);
  // copy assignment operator
  Cat& operator=(const Cat& copy);
  // polymorphism
  void makeSound(void) const;
};

#endif
