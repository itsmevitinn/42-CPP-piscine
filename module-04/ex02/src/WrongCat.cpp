#include "WrongCat.hpp"

// constructors
WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
  std::cout << "WrongCat default constructor called" << std::endl;
}

// copy constructor
WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
  std::cout << "WrongCat copy constructor called" << std::endl;
}

// destructor
WrongCat::~WrongCat(void) {
  std::cout << "WrongCat destructor called" << std::endl;
}

// copy assignment operator
WrongCat& WrongCat::operator=(const WrongCat& copy) {
  WrongAnimal::operator=(copy);
  std::cout << "WrongCat copy assignment operator called" << std::endl;
  return (*this);
}

// polymorphism
void WrongCat::makeSound(void) const {
  std::cout << "WrongCat: woeM woeM!" << std::endl;
}
