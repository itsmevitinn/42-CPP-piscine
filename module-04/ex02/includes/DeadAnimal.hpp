#ifndef DEADANIMAL_HPP
#define DEADANIMAL_HPP

#include <iostream>

//abstract class because have at least one pure virtual function
class DeadAnimal {
 protected:
  std::string _type;

 public:
  // constructors
  DeadAnimal(void);
  DeadAnimal(std::string name);
  // copy constructor
  DeadAnimal(const DeadAnimal& copy);
  // destructors
  virtual ~DeadAnimal(void);
  // copy assignment operator
  DeadAnimal& operator=(const DeadAnimal& copy);
  // member functions
  std::string getType(void) const;
  //pure virtual function
  virtual void makeSound(void) const = 0;
};

#endif
