#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
 protected:
  std::string _type;

 public:
  // constructors
  Animal(void);
  Animal(std::string name);
  // copy constructor
  Animal(const Animal& copy);
  // destructors
  ~Animal(void);
  // copy assignment operator
  Animal& operator=(const Animal& copy);
  // member functions
  std::string getType(void) const;
  virtual void makeSound(void) const;
};

#endif
