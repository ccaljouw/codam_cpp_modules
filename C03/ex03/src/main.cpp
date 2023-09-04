/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 12:14:51 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/02 11:44:45 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"
#include <iostream>

int	main( void )
{
	ClapTrap jan("Jan");
	ClapTrap klaas("Klaas");
	ClapTrap piet(jan);
	ScavTrap scav("Scav");
	FragTrap frag("Frag");
	DiamondTrap diamond("Diamond");

	std::cout << "--------------------------------------------------------" << std::endl;
	
	jan.getStatus();
	klaas.getStatus();
	piet.getStatus();
	scav.getStatus();
	frag.getStatus();
	diamond.getStatus();

	std::cout << "--------------------------------------------------------" << std::endl;

	jan.attack("Klaas");
	klaas.takeDamage(jan.getAttackDamage());
	jan.getStatus();
	klaas.getStatus();

	std::cout << "--------------------------------------------------------" << std::endl;
	
	scav.attack("Frag");
	frag.takeDamage(scav.getAttackDamage());
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
	diamond.whoAmI();
	diamond.guardGate();
	diamond.highFivesGuys();

	std::cout << "--------------------------------------------------------" << std::endl;
	return 0;
}
