#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
 private:
  Brain* _myBrain;

 public:
  // constructors
  Dog(void);
  // copy constructor
  Dog(const Dog& copy);
  // destructors
  ~Dog(void);
  // copy assignment operator
  Dog& operator=(const Dog& instance);
  // pure virtual function from base class
  void makeSound(void) const;
  // member functions
  Brain* getBrain(void) const;
};

#endif
