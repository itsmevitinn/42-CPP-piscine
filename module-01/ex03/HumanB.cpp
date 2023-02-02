#include "HumanB.hpp"

#include "Weapon.hpp"

HumanB::HumanB(std::string name) {
  this->_name = name;
}

void HumanB::setWeapon(Weapon& weaponInstance) {
  this->_myWeapon = &weaponInstance;
}

std::string HumanB::getName(void) const {
  return (this->_name);
}

void HumanB::attack(void) const {
  std::cout << this->getName() << " attacks with their " << this->_myWeapon->getType() << std::endl;
}
