#include <iostream>

//here, iter will receive any type of array, iterate through this array and apply the "f" function in each content of the array
template <typename T>
void iter(T* array, size_t length, void (*f)(const T&)) {
  for (size_t i = 0; i < length; i++) {
    (*f)(array[i]);
  }
}
//this function will print any type of value received as parameter
template <typename T>
void printArray(const T& value) {
  std::cout << value << std::endl;
}
