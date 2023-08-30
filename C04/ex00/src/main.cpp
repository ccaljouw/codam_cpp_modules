/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:48:41 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 13:17:45 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include <iostream>

int main( void ) {
	{
		std::cout << "--------------------------------" << std::endl;
		Cat	kitty;
		kitty.makeSound();
		std::cout << "--------------------------------" << std::endl;
		Cat kitty2("Kitty");
		kitty2.makeSound();
		std::cout << "--------------------------------" << std::endl;
		Dog	brutus;
		brutus.makeSound();
		std::cout << "--------------------------------" << std::endl;
		Dog	brutus2("Brutus");
		brutus2.makeSound();
		std::cout << "--------------------------------" << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	std::cout << "--------------------------------" << std::endl;
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wi = new WrongCat();
	std::cout << wi->getType() << " " << std::endl;
	wi->makeSound(); //will output the cat sound!
	wmeta->makeSound();
	delete wmeta;
	delete wi;
	std::cout << "--------------------------------" << std::endl;
	return 0;
}
