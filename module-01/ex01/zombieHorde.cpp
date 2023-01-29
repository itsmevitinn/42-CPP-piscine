#include "Zombie.hpp"
#include <iterator>

Zombie* zombieHorde( int N, std::string name ){
	Zombie* horde;
	Zombie* temp;

	horde = new Zombie[N];
	temp = horde;
	for(int i = 0; i < N; i++){
		temp->setName(name);
		temp++;
	}
	return (horde);
}
