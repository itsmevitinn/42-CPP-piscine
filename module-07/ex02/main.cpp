#include "Array.hpp"

template <typename T>
void printArray(Array<T>& array) {
  std::cout << "Size: " << array.size() << std::endl;
  for (unsigned int i = 0; i < array.size(); i++) {
    std::cout << array[i] << std::endl;
  }
}

template <typename T, typename C>
void populateArray(Array<T>& array, C content) {
  for (unsigned int i = 0; i < array.size(); i++) {
    array[i] = content;
  }
}

int main(void) {
  try {
    Array<std::string> words(6);
    Array<int> numbers(4);
    Array<int> copy(numbers);
    populateArray(words, "Salve");
    populateArray(numbers, 30);
    populateArray(copy, 40);
    printArray(words);
    printArray(numbers);
    printArray(copy);
		numbers[4];
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
