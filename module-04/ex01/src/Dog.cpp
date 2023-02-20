#include "../includes/Dog.hpp"

// constructors
Dog::Dog(void) : Animal("Dog"), _myBrain(new Brain()) {
  std::cout << "Dog default constructor called" << std::endl;
}

// copy constructor
Dog::Dog(const Dog& instance) {
  std::cout << "Dog copy constructor called" << std::endl;
  if (this != &instance) {
    *this = instance;
  } else {
    std::cout << "Cannot assign duplicated instances!" << std::endl;
  }
}

// destructor
Dog::~Dog(void) {
  delete this->_myBrain;
  std::cout << "Dog destructor called" << std::endl;
}

// copy assignment operator
Dog& Dog::operator=(const Dog& instance) {
  this->_type = instance._type;
  this->_myBrain = new Brain(*instance._myBrain);
  std::cout << "Dog copy assignment operator called" << std::endl;
  return (*this);
}

// polymorphism
void Dog::makeSound(void) const {
  std::cout << "Dog: Woof woof!" << std::endl;
}

// member function

Brain* Dog::getBrain(void) const {
  return (this->_myBrain);
}
