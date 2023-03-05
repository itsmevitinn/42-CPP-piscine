#include "MutantStack.hpp"

int main(void) {
  MutantStack<int> values;

  values.push(30);
  values.push(40);
  values.push(50);

  for (MutantStack<int>::iterator begin = values.begin(); begin != values.end(); begin++) {
    std::cout << "Values: " << *begin << std::endl;
  }
  return (0);
}
