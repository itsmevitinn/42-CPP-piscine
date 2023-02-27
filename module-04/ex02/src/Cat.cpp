#include "../includes/Cat.hpp"

// constructors
Cat::Cat(void) : AAnimal("Cat"), _myBrain(new Brain()) {
  std::cout << "Cat default constructor called" << std::endl;
}

// copy constructor
Cat::Cat(const Cat& instance) : AAnimal(instance) {
  std::cout << "Cat copy constructor called" << std::endl;
  //copying "Brain" here because the AAnimal copy constructor doesn't copy
  this->_myBrain = new Brain(*instance._myBrain);
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

// definindo a pure virtual function herdada da base class
void Cat::makeSound(void) const {
  std::cout << "Cat: Meow meow!" << std::endl;
}

// member function

Brain* Cat::getBrain(void) const {
  return (this->_myBrain);
}
