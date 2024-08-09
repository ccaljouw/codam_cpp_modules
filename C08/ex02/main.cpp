#include "MutantStack.hpp"
#include <iostream>


void leaks(void) {
	std::cout << "*********************************" << std::endl;
	system("leaks mutant -q");
	std::cout << "*********************************" << std::endl;
}

void printStackWithIterator(MutantStack<int> mutantStack) {
  std::cout << "Normal iterator: ";
  for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void printStackWithReverseIterator(MutantStack<int> mutantStack) {
  std::cout << "Reverse iterator: ";
  for (MutantStack<int>::reverse_iterator it = mutantStack.rbegin(); it != mutantStack.rend(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int main()
{
  atexit(leaks);
  
  std::cout << "\nCREATING EMPTY MUTANTSTACK" << std::endl;
  MutantStack<int> mutantStack;
  printStackWithIterator(mutantStack);
  std::cout << "Stack empty?: " << mutantStack.empty() << std::endl;
  std::cout << "Stack size: " << mutantStack.size() << std::endl; 

  std::cout << "\nADDING 5 ELEMENTS TO MUTANTSTACK" << std::endl;
  for (int i = 0; i < 5; i++) {
    mutantStack.push(i);
  }
  std::cout << "Stack empty?: " << mutantStack.empty() << std::endl;
  std::cout << "Stack size: " << mutantStack.size() << std::endl; 
  printStackWithIterator(mutantStack);
  printStackWithReverseIterator(mutantStack);

  std::cout << "\nSHOW STACK" << std::endl;
  std::cout << "Top of stack: " << mutantStack.top() << std::endl;
  std::cout << "Pop top of stack" << std::endl;
  mutantStack.pop();
  printStackWithIterator(mutantStack);
  printStackWithReverseIterator(mutantStack);

  std::cout << "\nCOPY MUTANTSTACK" << std::endl;
  MutantStack<int> mutantStackCopy(mutantStack);
  printStackWithIterator(mutantStackCopy);

  std::cout << "\nASSIGN MUTANTSTACK" << std::endl;
  MutantStack<int> mutantStackAssign;
  mutantStackAssign = mutantStack;
  printStackWithIterator(mutantStackAssign);

  std::cout << "\nCLEAR MUTANTSTACK" << std::endl;
  mutantStack.pop();
  std::cout << "Stack empty?: " << mutantStack.empty() << std::endl;
  std::cout << "Stack size: " << mutantStack.size() << std::endl;

  mutantStack.pop();
  std::cout << "Stack empty?: " << mutantStack.empty() << std::endl;
  std::cout << "Stack size: " << mutantStack.size() << std::endl;

  mutantStack.pop();
  std::cout << "Stack empty?: " << mutantStack.empty() << std::endl;
  std::cout << "Stack size: " << mutantStack.size() << std::endl;

  mutantStack.pop();
  std::cout << "Stack empty?: " << mutantStack.empty() << std::endl;
  std::cout << "Stack size: " << mutantStack.size() << std::endl;

  printStackWithIterator(mutantStack);
  printStackWithIterator(mutantStackCopy);
  printStackWithIterator(mutantStackAssign);

  return 0;
}