#include "../includes/Cat.hpp"

// constructors
Cat::Cat(void) : Animal("Cat"), _myBrain(new Brain()) {
  std::cout << "Cat default constructor called" << std::endl;
}

// copy constructor
Cat::Cat(const Cat& instance) {
  std::cout << "Cat copy constructor called" << std::endl;
  if (this != &instance) {
    *this = instance;
  } else {
    std::cout << "Cannot assign duplicated instances!" << std::endl;
  }
}

// destructor
Cat::~Cat(void) {
  delete this->_myBrain;
  std::cout << "Cat destructor called" << std::endl;
}

// copy assignment operator
Cat& Cat::operator=(const Cat& instance) {
  this->_type = instance._type;
  this->_myBrain = new Brain(*instance._myBrain);
  std::cout << "Cat copy assignment operator called" << std::endl;
  return (*this);
}

// polymorphism
void Cat::makeSound(void) const {
  std::cout << "Cat: Meow meow!" << std::endl;
}

// member function

Brain* Cat::getBrain(void) const {
  return (this->_myBrain);
}
