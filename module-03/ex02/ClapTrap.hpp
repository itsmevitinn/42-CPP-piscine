#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
 protected:
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
};

#endif
