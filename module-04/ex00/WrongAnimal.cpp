#include "WrongAnimal.hpp"

// constructors
WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : _type(name) {
  std::cout << "WrongAnimal (" << name << ") constructor called" << std::endl;
}

// copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& instance) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
  if (this != &instance) {
    *this = instance;
  } else {
    std::cout << "Cannot assign duplicated instances!" << std::endl;
  }
}
// destructor
WrongAnimal::~WrongAnimal(void) {
  std::cout << "WrongAnimal destructor called" << std::endl;
}
// copy assignment operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
  std::cout << "WrongAnimal copy assignment overload called" << std::endl;
  this->_type = copy._type;
  return (*this);
}

// member functions
std::string WrongAnimal::getType(void) const {
  return (this->_type);
}

void WrongAnimal::makeSound(void) const {
  std::cout << "WrongAnimal sekam a dnuos!" << std::endl;
}
