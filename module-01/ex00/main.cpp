#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void){
    Zombie* zombie;

    zombie = newZombie("bye malloc!");
    std::cout << "heap zombie name: " << zombie->getName() << std::endl;
    randomChump("stack zombie");
    delete zombie;
}
