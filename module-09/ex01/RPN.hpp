#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <iostream>
#include <stack>

class RPN {
 private:
  std::stack<float> stack;
  float first_operand;
  float second_operand;
  float result;

 public:
  void push(float number);
  void sum(void);
  void subtraction(void);
  void division(void);
  void multiplication(void);
  void printStack(void);
};

#endif
