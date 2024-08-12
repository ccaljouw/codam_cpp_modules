#include "RPN.hpp"

RPN::RPN() {
  this->_stack = new std::stack<int>();
}

RPN::RPN(const RPN& rhs) {
  *this = rhs;
}

RPN& RPN::operator=(const RPN& rhs) {
  if (this != &rhs) {
    this->_stack = rhs._stack;
  }
  return *this;
}

RPN::~RPN() {
  delete this->_stack;
}

void RPN::calculate(std::string IPN) {
  std::string tokens = "+-*/";
  for (char ch : IPN) {
    if (isdigit(ch)) {
      this->_stack->push(ch - '0');
    } else if (tokens.find(ch) != std::string::npos) {
      runOperation(ch);
    } else {
      if (ch != ' ') {
        std::cerr << "Invalid input" << std::endl;
        return;
      }
    }
  }
  if (this->_stack->size() != 1) {
    std::cerr << "Invalid input, not enough operands" << std::endl;
    return;
  } else {
    std::cout << this->_stack->top() << std::endl;
  }
}

void RPN::runOperation(char token) {
  if (this->_stack->size() < 2) {
    std::cerr << "Invallid input, not enough operands" << std::endl;
    return;
  }
  int b = _stack->top();
  _stack->pop();
  int a = _stack->top();
  _stack->pop();
  switch(token) {
    case '+':
      _stack->push(a + b);
      break;
    case '-':
      _stack->push(a - b);
      break;
    case '*':
      _stack->push(a * b);
      break;
    case '/':
      _stack->push(a / b);
      break;
  }
}

