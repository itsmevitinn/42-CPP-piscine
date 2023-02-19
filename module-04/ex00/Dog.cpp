#include "Dog.hpp"

// constructors
Dog::Dog(void) : Animal("Dog") {
  std::cout << "Dog default constructor called" << std::endl;
}

// copy constructor
Dog::Dog(const Dog& copy) : Animal(copy) {
  std::cout << "Dog copy constructor called" << std::endl;
}

// destructor
Dog::~Dog(void) {
  std::cout << "Dog destructor called" << std::endl;
}

// copy assignment operator
Dog& Dog::operator=(const Dog& copy) {
  Animal::operator=(copy);
  std::cout << "Dog copy assignment operator called" << std::endl;
  return (*this);
}

// polymorphism
void Dog::makeSound(void) const {
  std::cout << "Dog: Woof woof!" << std::endl;
}
