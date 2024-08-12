#ifndef RPN_H
# define RPN_H

#include <iostream>
#include <stack>
#include <string>

class RPN {
  public:
    RPN();
    RPN(const RPN& rhs);
    RPN& operator=(const RPN& rhs);
    ~RPN();

    void calculate(std::string IPN);

  private:
    std::stack<int>* _stack;
    bool runOperation(char op);
};

#endif