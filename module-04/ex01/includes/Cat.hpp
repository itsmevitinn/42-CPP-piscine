#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 private:
  Brain* _myBrain;

 public:
  // constructors
  Cat(void);
  // copy constructor
  Cat(const Cat& instance);
  // destructors
  ~Cat(void);
  // copy assignment operator
  Cat& operator=(const Cat& instance);
  // polymorphism
  void makeSound(void) const;
  // member functions
  Brain* getBrain(void) const;
};

#endif
