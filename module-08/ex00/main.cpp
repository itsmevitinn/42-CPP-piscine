#include "easyfind.hpp"

void printValue(int value) {
  std::cout << value << std::endl;
}

int main(void) {
  try {
    std::vector<int> numbers;
    for (int i = 0; i < 15; i++)
      numbers.push_back(i);

    std::vector<int>::iterator startNumbers = easyfind(numbers, 10);
    std::cout << "Vector beginning at: " << std::endl;
    for_each(startNumbers, numbers.end(), printValue);

    std::list<int> lst;
    for (int i = 0; i < 20; i++)
      lst.push_back(i);

    std::list<int>::iterator startLst = easyfind(lst, 15);
    std::cout << "List beginning at: " << std::endl;
    for_each(startLst, lst.end(), printValue);

    std::deque<int> forward;
    forward.push_front(40);
    std::deque<int>::iterator startForward = easyfind(forward, 15);
    (void)startForward;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
