#include "Cat.hpp"

// constructors
Cat::Cat(void) : Animal("Cat") {
  std::cout << "Cat default constructor called" << std::endl;
}

// copy constructor
Cat::Cat(const Cat& copy) : Animal(copy) {
  std::cout << "Cat copy constructor called" << std::endl;
}

// destructor
Cat::~Cat(void) {
  std::cout << "Cat destructor called" << std::endl;
}

// copy assignment operator
Cat& Cat::operator=(const Cat& copy) {
  Animal::operator=(copy);
  std::cout << "Cat copy assignment operator called" << std::endl;
  return (*this);
}

// polymorphism
void Cat::makeSound(void) const {
  std::cout << "Cat: Meow meow!" << std::endl;
}
