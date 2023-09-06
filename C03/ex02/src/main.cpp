/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 12:14:51 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/06 12:16:16 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include <iostream>

void leaks(void) {
	std::cout << "-------------------------------------" << std::endl;
	system("leaks fragtrap -q");
	std::cout << "-------------------------------------" << std::endl;
}

int	main( void )
{
	atexit(leaks);
	
	ClapTrap jan("Jan");
	ClapTrap klaas("Klaas");
	ClapTrap piet(jan);
	ScavTrap scav("scav");
	FragTrap frag("frag");

	std::cout << "--------------------------------------------------------" << std::endl;
	
	jan.getStatus();
	klaas.getStatus();
	piet.getStatus();
	scav.getStatus();
	frag.getStatus();

	std::cout << "--------------------------------------------------------" << std::endl;

	jan.attack("Klaas");
	klaas.takeDamage(jan.getAttackDamage());
	jan.getStatus();
	klaas.getStatus();

	std::cout << "--------------------------------------------------------" << std::endl;
	
	frag.attack("Scav");
	scav.takeDamage(frag.getAttackDamage());
	scav.getStatus();
	frag.getStatus();
	frag.attack("Scav");
	frag.attack("Scav");
	frag.attack("Scav");
	scav.takeDamage(frag.getAttackDamage());
	scav.takeDamage(frag.getAttackDamage());
	scav.takeDamage(frag.getAttackDamage());
	scav.getStatus();
	frag.getStatus();
	
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
	frag.highFivesGuys();

	std::cout << "--------------------------------------------------------" << std::endl;
	return 0;
}
