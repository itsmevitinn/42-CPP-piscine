#include "RPN.hpp"

void RPN::push(float number) {
  this->stack.push(number);
}

void RPN::sum(void) {
  this->first_operand = this->stack.top();
  this->stack.pop();
  this->second_operand = this->stack.top();
  this->stack.pop();
  this->result = this->first_operand + this->second_operand;
  this->stack.push(result);
}

void RPN::subtraction(void) {
  this->first_operand = this->stack.top();
  this->stack.pop();
  this->second_operand = this->stack.top();
  this->stack.pop();
  this->result = this->first_operand - this->second_operand;
  this->stack.push(result);
}

void RPN::division(void) {
  this->first_operand = this->stack.top();
  this->stack.pop();
  this->second_operand = this->stack.top();
  this->stack.pop();
  this->result = this->first_operand / this->second_operand;
  this->stack.push(result);
}

void RPN::multiplication(void) {
  this->first_operand = this->stack.top();
  this->stack.pop();
  this->second_operand = this->stack.top();
  this->stack.pop();
  this->result = this->first_operand * this->second_operand;
  this->stack.push(result);
}

void RPN::printStack(void) {
  while (!this->stack.empty()) {
    float a = this->stack.top();
    std::cout << a << std::endl;
    this->stack.pop();
  }
}