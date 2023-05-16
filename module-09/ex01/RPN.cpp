#include "RPN.hpp"

// constructors and destructors
RPN::RPN(void) {
}

RPN::RPN(const RPN& instance) : _stack(instance._stack) {
}

RPN::~RPN(void) {
}

// operator overload
RPN& RPN::operator=(const RPN& instance) {
  if (this != &instance)
    this->_stack = instance._stack;
  return (*this);
}

void RPN::addNumber(int number) {
  this->_stack.push(number);
}

void RPN::calculate(Operator type) {
  if (this->_stack.size() >= 2) {
    int first_operand = this->_stack.top();
    this->_stack.pop();
    int second_operand = this->_stack.top();
    this->_stack.pop();
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
    this->_stack.push(result);
  }
}

void RPN::printStack(void) {
  if (this->_stack.size() != 1)
    throw std::invalid_argument("Impossible to perform reverse polish notation");
  std::cout << this->_stack.top() << std::endl;
}