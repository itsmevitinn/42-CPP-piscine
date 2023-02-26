#include "Data.hpp"

int main(void) {
  Data myself;
  uintptr_t nbr;

  myself.name = "Vitor";
  myself.country = "Brazil";

  std::cout << "(Before serialize) Name: " << myself.name << std::endl;
  std::cout << "(Before serialize) Country: " << myself.country << std::endl;

  nbr = serialize(&myself);

  Data* ret = deserialize(nbr);

  std::cout << "(After serialize) Name: " << ret->name << std::endl;
  std::cout << "(After serialize) Country: " << ret->country << std::endl;
  return (0);
}
