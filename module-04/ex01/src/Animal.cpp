#include "Animal.hpp"

// constructors
Animal::Animal(void) : _type("Animal") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string name) : _type(name) {
  std::cout << "Animal (" << name << ") constructor called" << std::endl;
}

// copy constructor
Animal::Animal(const Animal& instance) {
  std::cout << "Animal copy constructor called" << std::endl;
  if (this != &instance) {
    *this = instance;
  } else {
    std::cout << "Cannot assign duplicated instances!" << std::endl;
  }
}
// destructor
Animal::~Animal(void) {
  std::cout << "Animal destructor called" << std::endl;
}
// copy assignment operator
Animal& Animal::operator=(const Animal& copy) {
  std::cout << "Animal copy assignment overload called" << std::endl;
  this->_type = copy._type;
  return (*this);
}

// member functions
std::string Animal::getType(void) const {
  return (this->_type);
}

void Animal::makeSound(void) const {
  std::cout << "Animal makes a sound!" << std::endl;
}
