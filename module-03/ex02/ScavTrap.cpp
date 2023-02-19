#include "ScavTrap.hpp"

// constructor
ScavTrap::ScavTrap(void) : ClapTrap() {
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
  std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  //editing the values that the constructor above has defined
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
  std::cout << "ScavTrap name constructor called" << std::endl;
}

// copy constructor
ScavTrap::ScavTrap(const ScavTrap& instance) : ClapTrap(instance) {
  std::cout << "ScavTrap copy constructor called" << std::endl;
}

// overload operator
ScavTrap& ScavTrap::operator=(const ScavTrap& instance) {
  ClapTrap::operator=(instance);
  std::cout << "ScavTrap copy assignment overload called" << std::endl;
  return (*this);
}

// destructor
ScavTrap::~ScavTrap(void) {
  std::cout << "ScavTrap destructor called" << std::endl;
}

// member functions
void ScavTrap::attack(const std::string& target) {
  if (this->_hitPoints <= 0) {
    std::cerr << this->_name << " can't attack because is dead!" << std::endl;
  } else if (this->_energyPoints <= 0) {
    std::cerr << this->_name << " can't attack because hasn't energy points!" << std::endl;
  } else {
    std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
  }
}

void ScavTrap::guardGate(void) {
  std::cout << this->_name << " is now in gate keeper mode" << std::endl;
}
