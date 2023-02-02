#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanB {
 private:
  std::string _name;
  Weapon* _myWeapon;

 public:
  HumanB(std::string name);
  void setWeapon(Weapon& weaponInstance);
  std::string getName(void) const;
  void attack(void) const;
};

#endif
