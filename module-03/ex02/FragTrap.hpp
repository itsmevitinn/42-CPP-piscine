#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
 public:
  // constructors
  FragTrap(void);
  FragTrap(std::string name);
  // copy constructor
  FragTrap(const FragTrap& instance);
  // destructor
  ~FragTrap(void);
  // operator overload
  FragTrap& operator=(const FragTrap& instance);
  // member functions
  void highFivesGuys(void);
};

#endif
