#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <iostream>
#include <stack>

enum Operator { sum, subtract, divide, multiply };

class RPN {
 private:
  std::stack<int> _stack;

 public:
  // constructors and destructors
  RPN(void);
  RPN(const RPN& instance);
  ~RPN(void);
  // copy assignment operator overload
  RPN& operator=(const RPN& instance);
  void addNumber(int number);
  void calculate(Operator type);
  void printStack(void);
};

#endif
