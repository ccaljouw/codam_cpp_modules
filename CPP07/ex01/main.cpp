#include "iter.hpp"
#include <iostream>

template<typename T>
void	display(T& element)
{
	std::cout << element << " ";
}
template<typename T>
void   add(T& element) {
  element++;
}

int main( void ) { 
  int	intArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  char charArray[10] ={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

  std::cout << "Print and add 1 to each element of the int array" << std::endl;
  iter(intArray, 10, &display);
  std::cout << std::endl;
  iter(intArray, 10, &add);
  iter(intArray, 10, &display);
  std::cout << std::endl;

  std::cout << "Print and add 1 to each element of the char array" << std::endl;
  iter(charArray, 10, &display);
  std::cout << std::endl;
  iter(charArray, 10, &add);
  iter(charArray, 10, &display);
  std::cout << std::endl;
  return 0; 
}