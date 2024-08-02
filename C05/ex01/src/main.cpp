/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/02 16:09:39 by cariencaljo   #+#    #+#                 */
/*   Updated: 2024/08/02 21:42:08 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

void leaks(void) {
	std::cout << "---------------------------------" << std::endl;
	system("leaks form -q");
	std::cout << "---------------------------------" << std::endl;
}

int main() {
  atexit(leaks);
}
