#include "Span.hpp"

int main(void) {
  srand(time(NULL));
  try {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Span slots(100);
    std::vector<int> numbers;
    for (int i = 0; i < 100; i++) {
      numbers.push_back(rand() % 100);
    }
    slots.addNumber(numbers.begin(), numbers.end());
    std::cout << slots.shortestSpan() << std::endl;
    std::cout << slots.longestSpan() << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Span slots(100);
    std::vector<int> numbers;
    for (int i = 0; i < 200; i++) {
      numbers.push_back(i);
    }
    slots.addNumber(numbers.begin(), numbers.end());
    std::cout << slots.shortestSpan() << std::endl;
    std::cout << slots.longestSpan() << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Span slots(1);
    slots.addNumber(30);
    std::cout << slots.shortestSpan() << std::endl;
    std::cout << slots.longestSpan() << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Span slots(10);
    std::cout << slots.shortestSpan() << std::endl;
    std::cout << slots.longestSpan() << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
