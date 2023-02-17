#include "ClapTrap.hpp"

int main(void){
	ClapTrap test;
	ClapTrap boy("vitor");
	ClapTrap anotherBoy("marcos");
	ClapTrap dummy(boy);

	dummy.attack("jonata");
	dummy.attack("jonata");
	dummy.attack("jonata");
	dummy.attack("jonata");
	dummy.attack("jonata");
	dummy.attack("jonata");
	dummy.attack("jonata");
	dummy.attack("jonata");
	dummy.attack("jonata");
	dummy.attack("jonata");
	dummy.attack("jonata");
	dummy.beRepaired(1);
	boy.takeDamage(5);
	boy.beRepaired(15);
	boy.takeDamage(10);
	boy.takeDamage(10);
	boy.takeDamage(1);
	boy.beRepaired(5);
	boy.attack("sergio");
	anotherBoy.beRepaired(20);
	anotherBoy.beRepaired(20);
	anotherBoy.beRepaired(20);
	anotherBoy.beRepaired(20);
	anotherBoy.attack("joao");
	anotherBoy.takeDamage(100);
	anotherBoy.takeDamage(1);
	anotherBoy.beRepaired(5);
	anotherBoy.attack("ratos");
}
