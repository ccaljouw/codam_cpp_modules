#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Not enough input to sort" << std::endl;
    return 1;
  }
  try {
    PmergeMe pmergeMe(argv);
    pmergeMe.sortFordJohnson();
    pmergeMe.showProcess();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}