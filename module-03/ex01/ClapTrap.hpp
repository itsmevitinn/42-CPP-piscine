#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
  //i could make data here as protected and use "this" in the derived classes instead of setters/getters member-functions of the base class
 private:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;

 public:
  // constructors
  ClapTrap(void);
  ClapTrap(std::string name);
  // copy constructor
  ClapTrap(const ClapTrap& instance);
  // destructor
  ~ClapTrap(void);
  // operator overload
  ClapTrap& operator=(const ClapTrap& instance);
  // member functions
  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  // getters
  std::string getName(void) const;
  unsigned int getHitPoints(void) const;
  unsigned int getEnergyPoints(void) const;
  unsigned int getAttackDamage(void) const;
  // setters
  void setName(std::string name);
  void setHitPoints(unsigned int hitPoints);
  void setEnergyPoints(unsigned int energyPoints);
  void setAttackDamage(unsigned int attackDamage);
};

#endif
