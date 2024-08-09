#include <iostream>
#include "Array.hpp"
#include <string>


void leaks(void) {
	std::cout << "*********************************" << std::endl;
	system("leaks array -q");
	std::cout << "*********************************" << std::endl;
}

#define ENTRIES 5
int main()
{
  atexit(leaks);

  std::cout << "Initialize empty array" << std::endl;
  Array<int> emptyArray;
  emptyArray.printElements();
  std::cout << "Array.size: " << emptyArray.size() << std::endl;

  std::cout << "\nArray of size ENTRIES" << std::endl;
  Array<int> numbers(ENTRIES);
  Array<std::string> strings(ENTRIES);
  numbers.printElements();
  strings.printElements();

  std::cout << "\nFill arrays with random values" << std::endl;
  std::srand(static_cast<unsigned int>((std::chrono::steady_clock::now().time_since_epoch().count())));
  std::string stringEntries[5] = {"first", "second", "third", "fourth", "fifth"};
  for (unsigned int i = 0; i < ENTRIES; i++) {
      const int value = rand() % 5;
      numbers[i] = value;
      strings[i] = stringEntries[value];
  }
  numbers.printElements();
  strings.printElements();

  std::cout << "\nTry to modify a value that is out of range" << std::endl;
  try {
      numbers[ENTRIES] = 0;
  }
  catch(const std::exception& e) {
      std::cerr << e.what() << '\n';
  }
  numbers.printElements();

  std::cout << "\ncopy and assignment operators" << std::endl;
  Array<int> assignmentOperator = numbers;
  Array<int> copyConstructor(assignmentOperator);
  numbers.printElements();
  assignmentOperator.printElements();
  copyConstructor.printElements();

  std::cout << "\nModify numbers array" << std::endl;
  for (unsigned int i = 0; i < ENTRIES; i++) {
      numbers[i] = rand() % 5;
  }
  numbers.printElements();
  assignmentOperator.printElements();
  copyConstructor.printElements();

  std::cout << "\nModify assignmentOperator array" << std::endl;
  for (unsigned int i = 0; i < ENTRIES; i++) {
      assignmentOperator[i] = rand() % 5;
  }
  numbers.printElements();
  assignmentOperator.printElements();
  copyConstructor.printElements();

  std::cout << "\nModify copyConstructor array" << std::endl;
  for (unsigned int i = 0; i < ENTRIES; i++) {
      copyConstructor[i] = rand() % 5;
  }
  numbers.printElements();
  assignmentOperator.printElements();
  copyConstructor.printElements();

  return 0;
}