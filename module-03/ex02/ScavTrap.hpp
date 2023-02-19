#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  // constructors
  ScavTrap(void);
  ScavTrap(std::string name);
  // copy constructor
  ScavTrap(const ScavTrap& instance);
  // destructor
  ~ScavTrap(void);
  // operator overload
  ScavTrap& operator=(const ScavTrap& instance);
  // member functions
  void attack(const std::string& target);
  void guardGate(void);
};

#endif
