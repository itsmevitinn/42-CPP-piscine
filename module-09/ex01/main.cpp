#include "RPN.hpp"

int isValidInput(std::string input) {
  for (unsigned int i = 0; i < input.size(); i++) {
    if (input[i] == '.' && (!isdigit(input[i - 1]) || !isdigit(input[i + 1])))
      return (0);
    else if (input[i] != '.' && input[i] != ' ' && !isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '/' && input[i] != '*')
      return (0);
  }
  return (1);
}

void handleCalculations(RPN& data, std::string input) {
  for (std::string::iterator it = input.begin(); it != input.end(); ++it) {
    if (isdigit(*it))
      data.addNumber(atoi(&*it));
    switch (*it) {
      case '+':
        data.calculate(sum);
        break;
      case '-':
        data.calculate(subtract);
        break;
      case '/':
        data.calculate(divide);
        break;
      case '*':
        data.calculate(multiply);
        break;
    }
  }
}

int main(int argc, char** argv) {
  try {
    if (argc != 2)
      throw std::invalid_argument("You must send only a single string as parameter!");
    std::string input = argv[1];
    if (!isValidInput(input) || input.size() == 1)
      throw std::invalid_argument("Invalid input!");
    RPN data;
    handleCalculations(data, input);
    data.printStack();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return (0);
}