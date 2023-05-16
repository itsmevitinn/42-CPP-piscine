#include "RPN.hpp"

void RPN::addNumber(float number) {
  this->stack.push(number);
}

void RPN::calculate(Operator type) {
  if (this->stack.size() >= 2) {
    float first_operand = this->stack.top();
    this->stack.pop();
    float second_operand = this->stack.top();
    this->stack.pop();
    float result;
    switch (type) {
      case sum:
        result = second_operand + first_operand;
        std::cout << second_operand << " + " << first_operand << " = " << result << std::endl;
        break;
      case subtract:
        result = second_operand - first_operand;
        std::cout << second_operand << " - " << first_operand << " = " << result << std::endl;
        break;
      case divide:
        result = second_operand / first_operand;
        std::cout << second_operand << " / " << first_operand << " = " << result << std::endl;
        break;
      case multiply:
        result = second_operand * first_operand;
        std::cout << second_operand << " * " << first_operand << " = " << result << std::endl;
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