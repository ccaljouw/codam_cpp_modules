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
  std::cout << "Calculating:\t" << IPN << std::endl;
  std::string tokens = "+-*/";
  for (char ch : IPN) {
    if (isdigit(ch)) {
      this->_stack->push(ch - '0');
    } else if (tokens.find(ch) != std::string::npos) {
      if (!runOperation(ch))
        return;
    } else {
      if (ch != ' ') {
        std::cerr << "Invalid input: invallid character" << std::endl;
        return;
      }
    }
  }
  if (this->_stack->size() != 1) {
    std::cerr << "Invalid input: remaining stack: " << std::endl;
    while(!this->_stack->empty()) {
      std::cout << this->_stack->top() << " ";
      this->_stack->pop();
    }
    std::cout << std::endl;
    return;
  } else {
    std::cout << "Result:\t\t" << this->_stack->top() << std::endl;
  }
}

bool RPN::runOperation(char token) {
  if (this->_stack->size() < 2) {
    std::cerr << "Invallid input: not enough operands" << std::endl;
    return false;
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
      if (a > INT_MAX / b){
        std::cerr << "Invallid input: multiplication overflow" << std::endl;
        return false;
      }
      _stack->push(a * b);
      break;
    case '/':
      if (b == 0) {
        std::cerr << "Invallid input: division by zero" << std::endl;
        return false;
      }
      _stack->push(a / b);
      break;
  }
  return true;
}

