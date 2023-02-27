#include "../includes/Cat.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
  AAnimal* horde[4];
  for (int i = 0; i < 2; i++) {
    horde[i] = new Dog();
    horde[i + 2] = new Cat();
  }
  for (int i = 0; i < 4; i++) {
    horde[i]->makeSound();
  }
  Cat copy(*(Cat*)horde[0]);
  std::cout << std::endl << "Copy type is : " << copy.getType() << std::endl;
  for (int i = 0; i < 100; i++) {
    std::cout << copy.getBrain()->getIdea(i) << std::endl;
  }
  std::cout << std::endl;
  for (int i = 0; i < 4; i++) {
    delete horde[i];
  }
  return (0);
}
