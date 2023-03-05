#include "MutantStack.hpp"

template <typename T>
void printValues(T value) {
  std::cout << "Values: " << value << std::endl;
}

int main(void) {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << "top: " << mstack.top() << std::endl;
  mstack.pop();
  std::cout << "size: " << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  std::cout << std::endl;
  std::cout << "Copy constructor and forward iterator" << std::endl;
  MutantStack<int> copy(mstack);
  for_each(copy.begin(), copy.end(), printValues<int>);
  std::cout << std::endl;

  std::cout << "reverse iterator" << std::endl;
  MutantStack<std::string> words;
  words.push("Friend");
  words.push("My");
  words.push("Hello");
  for_each(words.rbegin(), words.rend(), printValues<std::string>);
  std::cout << std::endl;

  std::cout << "Copy assignment operator and forward iterator" << std::endl;
  MutantStack<std::string> copyWords;
  copyWords = words;
  for_each(copyWords.begin(), copyWords.end(), printValues<std::string>);
  std::cout << std::endl;
  return (0);
}
