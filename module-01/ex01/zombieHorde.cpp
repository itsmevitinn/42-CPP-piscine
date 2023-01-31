#include <iterator>

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
  if (N <= 0)
    return (nullptr);
  Zombie* horde = new Zombie[N];
  Zombie* temp = horde;
  for (int i = 0; i < N; i++) {
    temp->setName(name);
    temp++;
  }
  return (horde);
}
