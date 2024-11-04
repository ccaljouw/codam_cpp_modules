/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:48:41 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/06 14:05:42 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"
#include <iostream>

int main( void ) {
	{
		std::cout << "\n------------------------------------------------------------------------------" << std::endl;
		std::cout << "                 TESTING CONSTRUCTORS, DESTRUCTORS AND SOUNDS                 " << std::endl;
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		Cat	kitty;
		kitty.makeSound();
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		Dog	brutus;
		brutus.makeSound();
		std::cout << "------------------------------------------------------------------------------"<< std::endl;
	}
	
	std::cout << "\n------------------------------------------------------------------------------" << std::endl;
	std::cout << "                                TESTING SOUNDS                                " << std::endl;
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	meta->makeSound(); 						//will output animal sound
	i->makeSound(); 						//will output the cat sound
	j->makeSound(); 						//will output the dog sound
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	delete meta;
	delete i;
	delete j;
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	
	std::cout << "\n------------------------------------------------------------------------------" << std::endl;
	std::cout << "                             TESTING WRONG SOUNDS                             " << std::endl;
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wi = new WrongCat();
	std::cout << "------------------------------------------------------------------------------"<< std::endl;
	std::cout << wmeta->getType() << " " << std::endl;
	std::cout << wi->getType() << " " << std::endl;
	std::cout << "------------------------------------------------------------------------------"<< std::endl;
	wmeta->makeSound();					//will output wrong animal sound!
	wi->makeSound(); 					//will output wrong animal sound!
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	delete wmeta;
	delete wi;
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	return 0;
}
