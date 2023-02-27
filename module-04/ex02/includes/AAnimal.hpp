#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

//abstract class because have at least one pure virtual function
class AAnimal {
 protected:
  std::string _type;

 public:
  // constructors
  AAnimal(void);
  AAnimal(std::string name);
  // copy constructor
  AAnimal(const AAnimal& copy);
  // destructors
  virtual ~AAnimal(void);
  // copy assignment operator
  AAnimal& operator=(const AAnimal& copy);
  // member functions
  std::string getType(void) const;
  //pure virtual function
  virtual void makeSound(void) const = 0;
};

#endif
