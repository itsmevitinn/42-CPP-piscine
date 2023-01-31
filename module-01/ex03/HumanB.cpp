#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
  this->_name = name;
}

void HumanB::setWeapon(Weapon* weaponInstance) {
  this->_myWeapon = weaponInstance;
}

std::string HumanB::getName(void) {
  return (this->_name);
}

void HumanB::attack(void) {
  std::cout << this->getName() << " attacks with their " << this->_myWeapon->getType() << std::endl;
}