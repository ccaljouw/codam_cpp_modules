/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/03 13:51:37 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/03 16:39:59 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <iomanip>

int main()
{
	std::cout << std::setw(80) << std::setfill('-') << "\n" <<std::endl;
	{
		Zombie no_name;
		no_name.announce();
	}
	std::cout << std::setw(80) << std::setfill('-') << "\n" <<std::endl;
	
	{
		Zombie with_name("original");
		with_name.announce();
	}
	std::cout << std::setw(80) << std::setfill('-') << "\n" <<std::endl;
	
	Zombie *newbe;
	newbe = newZombie("new_zombie");
	newbe->announce();
	delete newbe;
	std::cout << std::setw(80) << std::setfill('-') << "\n" <<std::endl;
	
	{
		randomChump("randomChump");
	}
	std::cout << std::setw(80) << std::setfill('-') << "\n" <<std::endl;
	return 0;
}