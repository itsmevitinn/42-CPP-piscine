#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weaponInstance) : _myWeapon(weaponInstance) {
  this->_name = name;
}

std::string HumanA::getName(void) const {
  return (this->_name);
}

void HumanA::attack(void) const {
  std::cout << this->getName() << " attacks with their " << this->_myWeapon.getType() << std::endl;
}
