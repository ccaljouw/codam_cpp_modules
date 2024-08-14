#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>


void leaks(void) {
	std::cout << "*********************************" << std::endl;
	system("leaks PmergeMe -q");
	std::cout << "*********************************" << std::endl;
}

int main(int argc, char **argv)
{
  atexit(leaks);
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