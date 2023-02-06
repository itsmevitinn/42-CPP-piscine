#include "HumanB.hpp"

#include "Weapon.hpp"

HumanB::HumanB(std::string name) {
  this->_name = name;
  this->_myWeapon = NULL;
}

void HumanB::setWeapon(Weapon& weaponInstance) {
  this->_myWeapon = &weaponInstance;
}

std::string HumanB::getName(void) const {
  return (this->_name);
}

void HumanB::attack(void) const {
  if (!this->_myWeapon) {
    std::cout << this->getName() << " doesn't have a weapon" << std::endl;
  } else {
    std::cout << this->getName() << " attacks with their " << this->_myWeapon->getType() << std::endl;
  }
}
