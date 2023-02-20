#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
 protected:
  std::string _type;

 public:
  // constructors
  WrongAnimal(void);
  WrongAnimal(std::string name);
  // copy constructor
  WrongAnimal(const WrongAnimal& copy);
  // destructors
  ~WrongAnimal(void);
  // copy assignment operator
  WrongAnimal& operator=(const WrongAnimal& copy);
  // member functions
  std::string getType(void) const;
  void makeSound(void) const;
};

#endif
