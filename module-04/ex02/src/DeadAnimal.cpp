#include "DeadAnimal.hpp"

// constructors
DeadAnimal::DeadAnimal(void) : _type("DeadAnimal") {
  std::cout << "DeadAnimal default constructor called" << std::endl;
}

DeadAnimal::DeadAnimal(std::string name) : _type(name) {
  std::cout << "DeadAnimal (" << name << ") constructor called" << std::endl;
}

// copy constructor
DeadAnimal::DeadAnimal(const DeadAnimal& instance) {
  std::cout << "DeadAnimal copy constructor called" << std::endl;
  if (this != &instance) {
    *this = instance;
  } else {
    std::cout << "Cannot assign duplicated instances!" << std::endl;
  }
}
// destructor
DeadAnimal::~DeadAnimal(void) {
  std::cout << "DeadAnimal destructor called" << std::endl;
}
// copy assignment operator
DeadAnimal& DeadAnimal::operator=(const DeadAnimal& copy) {
  std::cout << "DeadAnimal copy assignment overload called" << std::endl;
  this->_type = copy._type;
  return (*this);
}

// member functions
std::string DeadAnimal::getType(void) const {
  return (this->_type);
}
