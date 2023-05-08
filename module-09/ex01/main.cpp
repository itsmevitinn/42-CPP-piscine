#include "RPN.hpp"

int isValidNumbers(std::string numbers) {
  for (unsigned int i = 0; i < numbers.size(); i++) {
    if (numbers[i] == '.' && (!isdigit(numbers[i - 1]) || !isdigit(numbers[i + 1])))
      return (0);
    else if (numbers[i] != '.' && numbers[i] != ' ' && !isdigit(numbers[i]))
      return (0);
  }
  return (1);
}

void fillStack(RPN& stack, std::string numbers) {
  std::string temp;

  for (unsigned int i = 0; i < numbers.size(); i++) {
    while (isspace(numbers[i]))
      i++;
    while (isdigit(numbers[i]) || numbers[i] == '.')
      temp += numbers[i++];
    stack.push(atof(temp.c_str()));
    temp = "";
  }
}

int main(int argc, char** argv) {
  std::string numbers = argv[1];
  if (argc != 2) {
    std::cerr << "Your must send a single string!" << std::endl;
    return (1);
  } else if (!isValidNumbers(numbers) || numbers.size() == 1) {
    std::cerr << "Invalid set of numbers!" << std::endl;
    return (1);
  }
  RPN stack;
  fillStack(stack, numbers);
  // performOperators(stack);
  stack.printStack();
  return (0);
}