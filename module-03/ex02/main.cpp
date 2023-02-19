#include "FragTrap.hpp"

int main(void) {
  FragTrap boy;
  FragTrap dummy(boy);
  FragTrap anotherBoy("marcos");

  dummy.highFivesGuys();
  dummy.attack("im dummy");
  dummy.beRepaired(1);
  dummy.takeDamage(50);
  dummy.takeDamage(100);
  dummy.takeDamage(1);
  dummy.beRepaired(1);
  dummy.attack("im dummy");
  boy.highFivesGuys();
  boy.attack("im boy");
  boy.beRepaired(1);
  boy.takeDamage(50);
  boy.takeDamage(100);
  boy.takeDamage(1);
  boy.beRepaired(1);
  boy.attack("im boy");
  anotherBoy.highFivesGuys();
  anotherBoy.attack("im anotherboy");
  anotherBoy.beRepaired(1);
  anotherBoy.takeDamage(50);
  anotherBoy.takeDamage(100);
  anotherBoy.takeDamage(1);
  anotherBoy.beRepaired(1);
  anotherBoy.attack("im anotherboy");
}
