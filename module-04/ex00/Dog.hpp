#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>

#include "Animal.hpp"

class Dog : public Animal {
 public:
  // constructors
  Dog(void);
  // copy constructor
  Dog(const Dog& copy);
  // destructors
  ~Dog(void);
  // copy assignment operator
  Dog& operator=(const Dog& copy);
  // polymorphism
  void makeSound(void) const;
};

#endif
