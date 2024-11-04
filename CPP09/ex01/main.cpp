#include "RPN.hpp"
#include <iostream>

// An Inverted Polish Notation (IPN) expression, also known as Reverse Polish Notation (RPN), 
// is a mathematical notation in which every operator follows all of its operands. 
// It eliminates the need for parentheses to denote the order of operations.
int main(int argc, char **argv)
{
  if (argc == 1) {
    std::cerr << "Please provide IPN" << std::endl;
    return 1;
  }
  RPN polishCalculator;
  polishCalculator.calculate(argv[1]);
  return 0;
}