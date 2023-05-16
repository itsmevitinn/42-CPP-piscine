#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <iostream>
#include <stack>

enum Operator { sum, subtract, divide, multiply };

class RPN {
   private:
    std::stack<float> stack;

   public:
    void addNumber(float number);
    void calculate(Operator type);
    void printStack(void);
};

#endif
