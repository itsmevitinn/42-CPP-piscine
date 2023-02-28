#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  WrongAnimal* test = new WrongCat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  //will output the cat & dog sounds because Animal makeSound() is a virtual member-function
  i->makeSound();
  j->makeSound();
  meta->makeSound();
  //will not print the wrongcat sound because WrongAnimal makeSound() is not a virtual member-function
  test->makeSound();
  delete meta;
  delete j;
  delete i;
  delete test;
  return 0;
}
