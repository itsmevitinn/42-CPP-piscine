#include "ClapTrap.hpp"
// constructors
ClapTrap::ClapTrap(void) : _name("Robot"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap Name constructor called" << std::endl;
}
// copy constructor
ClapTrap::ClapTrap(const ClapTrap& instance) {
  std::cout << "ClapTrap copy constructor called" << std::endl;
  if (this != &instance) {
    *this = instance;
  } else {
    std::cout << "Cannot assign duplicated instances!" << std::endl;
  }
}
// destructor
ClapTrap::~ClapTrap(void) {
  std::cout << "ClapTrap destructor called" << std::endl;
}
// operator overload
ClapTrap& ClapTrap::operator=(const ClapTrap& instance) {
  std::cout << "ClapTrap copy assignment overload called" << std::endl;
  this->_name = instance._name;
  this->_hitPoints = instance._hitPoints;
  this->_energyPoints = instance._energyPoints;
  this->_attackDamage = instance._attackDamage;
  return (*this);
}

// member functions
void ClapTrap::attack(const std::string& target) {
  if (this->_hitPoints <= 0) {
    std::cout << this->_name << " can't attack because is dead!" << std::endl;
  } else if (this->_energyPoints <= 0) {
    std::cout << this->_name << " can't attack because hasn't energy points!" << std::endl;
  } else {
    std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (!this->_hitPoints) {
    std::cout << this->_name << " can't receive more damage because is dead!" << std::endl;
  } else if (amount >= this->_hitPoints) {
    std::cout << this->_name << " takes " << this->_hitPoints << " damage and dies!" << std::endl;
    this->_hitPoints = 0;
  } else {
    this->_hitPoints -= amount;
    std::cout << this->_name << " takes " << amount << " damage!" << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->_hitPoints <= 0) {
    std::cout << this->_name << " can't be repaired because is dead!" << std::endl;
  } else if (this->_energyPoints <= 0) {
    std::cout << this->_name << " can't be repaired because hasn't energyPoints!" << std::endl;
  } else {
    this->_hitPoints += amount;
    this->_energyPoints--;
    std::cout << this->_name << " heals " << amount << " hitpoints!" << std::endl;
  }
}
