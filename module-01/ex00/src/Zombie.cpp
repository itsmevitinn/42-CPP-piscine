#include "../includes/Zombie.hpp"

void Zombie::setName(std::string name) {
  this->_name = name;
}

std::string Zombie::getName(void) {
  return (this->_name);
}

void Zombie::announce(void) {
    std::cout << this->getName() + ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void){
  std::cout << this->getName() << " was destroyed" << std::endl;
}