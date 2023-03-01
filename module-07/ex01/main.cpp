#include "iter.hpp"

int main(void) {
  int array[] = {3, 4, 5};
  int length = sizeof(array) / sizeof(array[0]);
  // implicit instanciation of "printArray"
  ::iter(array, length, &printArray);

  std::string names[] = {"Vitor", "Camila", "Gabriel"};
  // implicit instanciation of "printArray"
  ::iter(names, 3, &printArray);

  float numbers[] = {5.3, 10.3f, -104.22, -40};
  // explicit instanciation of "printArray"
  ::iter(numbers, 4, &printArray<float>);
  return (0);
}
