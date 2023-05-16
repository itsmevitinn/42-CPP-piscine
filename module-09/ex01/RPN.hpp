#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <iostream>
#include <stack>

enum Operator { sum, subtract, divide, multiply };

class RPN {
   private:
    std::stack<int> stack;

   public:
    void addNumber(int number);
    void calculate(Operator type);
    void printStack(void);
};

#endif
