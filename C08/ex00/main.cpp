#include "easyfind.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>


void leaks(void) {
	std::cout << "*********************************" << std::endl;
	system("leaks find -q");
	std::cout << "*********************************" << std::endl;
}

int main()
{
  atexit(leaks);
  std::vector<int> intVector {1, 2, 3, 4, 5, 6};
  std::list<int> intList {1, 2, 3, 4, 5, 6};
  std::deque<int> intDeque {1, 2, 3, 4, 5, 6};

  try {
    std::cout << "----------------------------------" << std::endl;
    auto found = easyfind(intVector, 1);
    std::cout << "Found " << *found << " in intVector" << std::endl;
    easyfind(intVector, 7);
  } catch (std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << "----------------------------------" << std::endl;
    auto found = easyfind(intList, 1);
    std::cout << "Found " << *found << " in intList" << std::endl;
    easyfind(intList, 7);
  } catch (std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << "----------------------------------" << std::endl;
    auto found = easyfind(intDeque, 1);
    std::cout << "Found " << *found << " in intDeque" << std::endl;
    easyfind(intDeque, 7);
  } catch (std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}