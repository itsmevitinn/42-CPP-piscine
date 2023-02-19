#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
  // editing the protected values of ClapTrap
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
  std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
  std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& instance) : ClapTrap(instance) {
  std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void) {
  std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& instance) {
  ClapTrap::operator=(instance);
  std::cout << "FragTrap copy assignment overload called" << std::endl;
  return (*this);
}

void FragTrap::highFivesGuys(void) {
  std::cout << "Hey, im giving you a high five!" << std::endl;
}
