/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/16 15:14:53 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/22 12:29:06 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(void)
{
	Harl harry;

	std::cout << "--------------------------------------------------------" << std::endl;
	harry.complain("DEBUG");
	std::cout << "--------------------------------------------------------" << std::endl;
	harry.complain("INFO");
	std::cout << "--------------------------------------------------------" << std::endl;
	harry.complain("WARNING");
	std::cout << "--------------------------------------------------------" << std::endl;
	harry.complain("ERROR");
	std::cout << "--------------------------------------------------------" << std::endl;
	harry.complain("random");
	std::cout << "--------------------------------------------------------" << std::endl;
	return 0;
}