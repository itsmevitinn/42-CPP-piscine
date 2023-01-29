#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void) {
	int N = 20;
  Zombie* firstZombie = zombieHorde(N, "ratos");
	Zombie* temp = firstZombie;

  for (int i = 0; i < N; i++) {
    temp->announce();
    temp++;
  }
	delete[] firstZombie;
}
