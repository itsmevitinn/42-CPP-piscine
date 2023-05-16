#include "RPN.hpp"

void RPN::addNumber(int number) {
  this->stack.push(number);
}

void RPN::calculate(Operator type) {
  if (this->stack.size() >= 2) {
    int first_operand = this->stack.top();
    this->stack.pop();
    int second_operand = this->stack.top();
    this->stack.pop();
    int result;
    switch (type) {
      case sum:
        result = second_operand + first_operand;
        break;
      case subtract:
        result = second_operand - first_operand;
        break;
      case divide:
        result = second_operand / first_operand;
        break;
      case multiply:
        result = second_operand * first_operand;
        break;
    }
    this->stack.push(result);
  }
}

void RPN::printStack(void) {
  if (this->stack.size() != 1)
    throw std::invalid_argument("Impossible to perform reverse polish notation");
  std::cout << this->stack.top() << std::endl;
}