/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/02 16:09:39 by cariencaljo   #+#    #+#                 */
/*   Updated: 2024/08/08 15:14:12 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

void leaks(void) {
	std::cout << "*********************************" << std::endl;
	system("leaks serialize -q");
	std::cout << "*********************************" << std::endl;
}

int main()
{
  Data newData;

  newData.number = 42;
  newData.text = "awasome";

  std::cout << "Data before serialization: " << newData << std::endl;
  
  uintptr_t  newUintPtr = Serializer::serialize(&newData);
  std::cout << "Data after serialization: " << newData << std::endl;
  
  Serializer::deserialize(newUintPtr);
  std::cout << "Data after deserialization: " << newData << std::endl;
}
