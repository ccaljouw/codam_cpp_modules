/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:48:41 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/04 12:06:46 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/MateriaSource.hpp"
#include "../include/Character.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

void	leaks(void) {
	std::cout << "---------------------------------------------------" << std::endl;
	system("leaks interface -q");
	std::cout << "---------------------------------------------------" << std::endl;
}

int main() {

	atexit(leaks);
	IMateriaSource* src = new MateriaSource(); 
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->unequip(4);

	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me; 
	delete src;
	
	return 0; 
}
