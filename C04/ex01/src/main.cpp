/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:48:41 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 16:01:47 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include <iostream>

int main( void ) {
	
	{
		const Cat* b = new Cat();
		std::cout << "---------------------------------" << std::endl;
		Cat	newCat(*b);
		std::cout << "---------------------------------" << std::endl;
		delete b;
		std::cout << "---------------------------------" << std::endl;
		const Dog* a = new Dog();
		std::cout << "---------------------------------" << std::endl;
		Dog	newDog(*a);
		std::cout << "---------------------------------" << std::endl;
		delete a;
		std::cout << "---------------------------------" << std::endl;
	}
	std::cout << "---------------------------------" << std::endl;
	const Animal* a = new Dog();
	const Animal* b = new Cat();
	std::cout << "---------------------------------" << std::endl;
	delete b;
	delete a;
	std::cout << "---------------------------------" << std::endl;
	Animal	*animalArray[10];
	std::cout << "---------------------------------" << std::endl;
	for(int i = 0; i < 10; i++)
	{
		std::cout << i << std::endl;
		if (i % 2)
			animalArray[i] = new Cat();
		else
			animalArray[i] = new Dog();
		std::cout << "---------------------------------" << std::endl;
	}
	for(int i = 0; i < 10; i++) {
		std::cout << i << std::endl;
		delete animalArray[i];	
		std::cout << "---------------------------------" << std::endl;
	}
	return 0;
}
