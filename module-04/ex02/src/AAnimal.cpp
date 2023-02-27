#include "AAnimal.hpp"

// constructors
AAnimal::AAnimal(void) : _type("AAnimal") {
  std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string name) : _type(name) {
  std::cout << "AAnimal (" << name << ") constructor called" << std::endl;
}

// copy constructor
AAnimal::AAnimal(const AAnimal& instance) {
  std::cout << "AAnimal copy constructor called" << std::endl;
  if (this != &instance) {
    *this = instance;
  } else {
    std::cout << "Cannot assign duplicated instances!" << std::endl;
  }
}
// destructor
AAnimal::~AAnimal(void) {
  std::cout << "AAnimal destructor called" << std::endl;
}
// copy assignment operator
AAnimal& AAnimal::operator=(const AAnimal& copy) {
  std::cout << "AAnimal copy assignment overload called" << std::endl;
  this->_type = copy._type;
  return (*this);
}

// member functions
std::string AAnimal::getType(void) const {
  return (this->_type);
}
