#include <iostream>
#include "Array.hpp"
#include <string>

#define ENTRIES 5
int main()
{
  std::cout << "Initialize empty array" << std::endl;
  Array<int> emptyArray;
  emptyArray.printElements();
  std::cout << "Array.size: " << emptyArray.size() << std::endl;

  std::cout << "\nArray of size " << ENTRIES << std::endl;
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

  std::cout << "\nTry to modify an index that is out of range" << std::endl;
  try {
      numbers[ENTRIES] = 0;
  }
  catch(const std::exception& e) {
      std::cerr << e.what() << '\n';
  }

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

// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(nullptr));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }