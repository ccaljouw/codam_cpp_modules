/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/16 15:14:53 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/22 12:02:59 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Harl harry;
	if (argc != 2) {
		std::cout << "incorrect number of arguments provided" << std::endl;
		return 0;
	}
	harry.complain(argv[1]);
	return 0;
}