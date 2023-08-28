/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 12:14:51 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/28 15:54:36 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main( void )
{
	ClapTrap jan("Jan");
	ClapTrap klaas("Klaas");
	ClapTrap piet(jan);
	ScavTrap scav("scav");

	std::cout << "--------------------------------------------------------" << std::endl;
	
	jan.getStatus();
	klaas.getStatus();
	piet.getStatus();
	scav.getStatus();

	std::cout << "--------------------------------------------------------" << std::endl;

	jan.attack("Klaas");
	klaas.takeDamage(jan.getAttackDamage());
	jan.getStatus();
	klaas.getStatus();

	std::cout << "--------------------------------------------------------" << std::endl;
	
	scav.attack("Jan");
	jan.takeDamage(scav.getAttackDamage());
	scav.getStatus();
	jan.getStatus();
	
	std::cout << "--------------------------------------------------------" << std::endl;
	
	klaas.beRepaired(jan.getAttackDamage());
	klaas.getStatus();

	std::cout << "--------------------------------------------------------" << std::endl;

	jan.attack("Klaas");
	klaas.takeDamage(jan.getAttackDamage());
	jan.getStatus();
	klaas.getStatus();
	
	std::cout << "--------------------------------------------------------" << std::endl;

	scav.guardGate();

	std::cout << "--------------------------------------------------------" << std::endl;
	return 0;
}
