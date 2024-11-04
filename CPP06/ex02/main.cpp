/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/02 16:09:39 by cariencaljo   #+#    #+#                 */
/*   Updated: 2024/08/08 17:31:23 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "type.hpp"

void leaks(void) {
	std::cout << "*********************************" << std::endl;
	system("leaks type -q");
	std::cout << "*********************************" << std::endl;
}

int main()
{
  for(int i = 0; i < 10; i++) {
    Base* instance = generate();
    identify(instance);
    identify(*instance);
    delete instance;
    std::cout << "---------------------------------" << std::endl;
  }
    
}