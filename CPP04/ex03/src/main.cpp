/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:48:41 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/08 13:35:58 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/MateriaSource.hpp"
#include "../include/Character.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

void leaks(void) {
	std::cout << "-----------------------------------------" << std::endl;
	system("leaks interface -q");
	std::cout << "-----------------------------------------" << std::endl;
}

int main() {
	atexit(leaks);
	
	IMateriaSource* src = new MateriaSource(); 
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->printInventory();
	std::cout << "-----------------------------------------" << std::endl;
	
	ICharacter* me = new Character("me");
	me->printInventory();
	std::cout << "-----------------------------------------" << std::endl;
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << "-----------------------------------------" << std::endl;
	me->printInventory();
	std::cout << "-----------------------------------------" << std::endl;
	me->unequip(2);
	me->printInventory();
	std::cout << "-----------------------------------------" << std::endl;

	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	delete bob;
	delete me;
	delete src;
	
	return 0; 
}
