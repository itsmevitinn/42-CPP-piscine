#include "ScavTrap.hpp"

// constructor
ScavTrap::ScavTrap(void) : ClapTrap() {
  // we could define the base class variables as protected and edit data here with "this->" instead of setters member-functions
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(20);
  std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  //editing the values that the constructor above has defined
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(20);
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
  if (getHitPoints() <= 0) {
    std::cerr << getName() << " can't attack because is dead!" << std::endl;
  } else if (getEnergyPoints() <= 0) {
    std::cerr << getName() << " can't attack because hasn't energy points!" << std::endl;
  } else {
    std::cout << "ScavTrap " << getName() << " attacks " << target << " causing " << getAttackDamage() << " points of damage!" << std::endl;
    setEnergyPoints(getEnergyPoints() - 1);
  }
}

void ScavTrap::guardGate(void) {
  std::cout << getName() << " is now in gate keeper mode" << std::endl;
}
