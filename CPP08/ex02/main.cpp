#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <deque>


void leaks(void) {
	std::cout << "*********************************" << std::endl;
	system("leaks mutant -q");
	std::cout << "*********************************" << std::endl;
}

template <typename T>
void printStackWithIterator(T mutantStack) {
  std::cout << "Normal iterator: ";
  for (typename T::iterator it = mutantStack.begin(); it != mutantStack.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void printStackWithReverseIterator(T mutantStack) {
  std::cout << "Reverse iterator: ";
  for (typename T::reverse_iterator it = mutantStack.rbegin(); it != mutantStack.rend(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void addElementsPushBack(T& container) {
  for (int i = 0; i < 5; i++) {
    container.push_back(i);
  }
}

template <typename T>
void addElementsPush(T& container) {
  for (int i = 0; i < 5; i++) {
    container.push(i);
  }
}

template <typename T>
void showContainer(T container) {
  printStackWithIterator(container);
  printStackWithReverseIterator(container);
  std::cout << "Stack empty?: " << container.empty() << std::endl;
  std::cout << "Stack size: " << container.size() << "\n" << std::endl;
}

int main()
{
  atexit(leaks);
  
  std::cout << "\nCREATING EMPTY CONTAINERS" << std::endl;
  std::cout << "---------------------------------" << std::endl;
  MutantStack<int> mutantStack;
  std::list<int> listContainer;
  std::deque<int> dequeContainer;
  showContainer(mutantStack);
  showContainer(listContainer);
  showContainer(dequeContainer);

  std::cout << "---------------------------------" << std::endl;
  
  std::cout << "\nADDING ELEMENTS TO CONTAINERS" << std::endl;
  std::cout << "---------------------------------" << std::endl;
  addElementsPush(mutantStack);
  addElementsPushBack(listContainer);
  addElementsPushBack(dequeContainer);
  showContainer(mutantStack);
  showContainer(listContainer);
  showContainer(dequeContainer);
  std::cout << "---------------------------------" << std::endl;

  std::cout << "\nPOP CONTAINER ELEMENT" << std::endl;
  std::cout << "---------------------------------" << std::endl;
  mutantStack.pop();
  listContainer.pop_back();
  dequeContainer.pop_back();
  std::cout << "Top of stack: " << mutantStack.top() << std::endl;
  showContainer(mutantStack);
  std::cout << "Top of stack: " << listContainer.back() << std::endl;
  showContainer(listContainer);
  std::cout << "Top of stack: " << dequeContainer.back() << std::endl;
  showContainer(dequeContainer);
  std::cout << "---------------------------------" << std::endl;

  std::cout << "\nCOPY MUTANTSTACK" << std::endl;
  std::cout << "---------------------------------" << std::endl;
  MutantStack<int> containterCopy(mutantStack);
  printStackWithIterator(containterCopy);
  std::cout << "---------------------------------" << std::endl;

  std::cout << "\nASSIGN MUTANTSTACK" << std::endl;
  std::cout << "---------------------------------" << std::endl;
  MutantStack<int> containerAssign = mutantStack;
  printStackWithIterator(containerAssign);
  std::cout << "---------------------------------" << std::endl;

  std::cout << "\nCOPY MUTANTSTACK TO STACK" << std::endl;
  std::cout << "---------------------------------" << std::endl;
  std::stack<int> stackCopy(mutantStack);
  std::cout << "Top of stack: " << stackCopy.top() << std::endl;
  std::cout << "Stack empty?: " << stackCopy.empty() << std::endl;
  std::cout << "Stack size: " << stackCopy.size() << "\n" << std::endl;
  std::cout << "Top of stack: " << mutantStack.top() << std::endl;
  std::cout << "Stack empty?: " << mutantStack.empty() << std::endl;
  std::cout << "Stack size: " << mutantStack.size() << "\n" << std::endl;
  std::cout << "---------------------------------" << std::endl;

  std::cout << "\nCLEAR MUTANTSTACK" << std::endl;
  std::cout << "---------------------------------" << std::endl;
  mutantStack.pop();
  mutantStack.pop();
  mutantStack.pop();
  mutantStack.pop();
  printStackWithIterator(mutantStack);
  printStackWithIterator(containterCopy);
  printStackWithIterator(containerAssign);
  std::cout << "---------------------------------" << std::endl;


  return 0;
}