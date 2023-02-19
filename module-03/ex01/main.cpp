#include "ScavTrap.hpp"

int main(void){
	ScavTrap boy;
	ScavTrap dummy(boy);
	ScavTrap anotherBoy("marcos");

	dummy.guardGate();
	dummy.attack("im dummy");
	dummy.beRepaired(1);
	dummy.takeDamage(50);
	dummy.takeDamage(100);
	dummy.takeDamage(1);
	dummy.beRepaired(1);
	dummy.attack("im dummy");
	boy.guardGate();
	boy.attack("im boy");
	boy.beRepaired(1);
	boy.takeDamage(50);
	boy.takeDamage(100);
	boy.takeDamage(1);
	boy.beRepaired(1);
	boy.attack("im boy");
	anotherBoy.guardGate();
	anotherBoy.attack("im anotherboy");
	anotherBoy.beRepaired(1);
	anotherBoy.takeDamage(50);
	anotherBoy.takeDamage(100);
	anotherBoy.takeDamage(1);
	anotherBoy.beRepaired(1);
	anotherBoy.attack("im anotherboy");
}
