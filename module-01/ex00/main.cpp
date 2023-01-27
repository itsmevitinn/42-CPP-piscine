#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void){
    Zombie* zombie;

    zombie = newZombie("ratos gordos");
    std::cout << "returned name: " << zombie->getName() << std::endl;
    randomChump("kimuras");
    delete zombie;
}