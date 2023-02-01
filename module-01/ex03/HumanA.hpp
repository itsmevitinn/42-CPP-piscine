#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanA {
 private:
  std::string _name;
  Weapon& _myWeapon;

 public:
  HumanA(std::string name, Weapon& weaponInstance);
  std::string getName(void);
  void attack(void);
};

#endif
