/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:48:41 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/08 12:08:46 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include <iostream>

void leaks(void) {
	std::cout << "---------------------------------" << std::endl;
	system("leaks brain -q");
	std::cout << "---------------------------------" << std::endl;
}

int main( void ) {
	
	atexit(leaks);
	{
		std::cout << "\n------------------------------------------------------------------------------" << std::endl;
		std::cout << "                     TESTING CONSTRUCTORS AND DESTRUCTORS                     " << std::endl;
		std::cout << "                           AND SHOW DEEP COPY BRAIN                           " << std::endl;
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		const Cat* b = new Cat();
		b->getBrain()->setIdea("I have an idea :)");
		std::cout << "\nb has ideas: " << std::endl;
		b->getBrain()->printIdeas();
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		Cat	newCat(*b);
		std::cout << "\nnewCat has ideas:" << std::endl;
		newCat.getBrain()->printIdeas();
		newCat.getBrain()->setIdea("I have a new idea :)");
		std::cout << "\nnewCat now has ideas:" << std::endl;
		newCat.getBrain()->printIdeas();
		std::cout << "\nb now has ideas:" << std::endl;
		b->getBrain()->printIdeas();
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		delete b;
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		const Dog* a = new Dog();
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		Dog	newDog(*a);
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		delete a;
		std::cout << "------------------------------------------------------------------------------" << std::endl;
	}
	
	std::cout << "\n------------------------------------------------------------------------------" << std::endl;
	std::cout << "                   MAKING SURE NO LEAKS WITH NEW AND DELETE                   " << std::endl;
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	const Animal* a = new Dog();
	const Animal* b = new Cat();
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	delete b;
	delete a;
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	std::cout << "\n------------------------------------------------------------------------------" << std::endl;
	std::cout << "                  CREATING AND DELETING ARRAY OF CATS AND DOGS                " << std::endl;
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	Animal	*animalArray[10];
		std::cout << "------------------------------------------------------------------------------" << std::endl;
	for(int i = 0; i < 10; i++)
	{
		std::cout << i << std::endl;
		if (i % 2)
			animalArray[i] = new Cat();
		else
			animalArray[i] = new Dog();
		std::cout << "------------------------------------------------------------------------------" << std::endl;
	}
	for(int i = 0; i < 10; i++) {
		std::cout << i << std::endl;
		delete animalArray[i];	
		std::cout << "------------------------------------------------------------------------------" << std::endl;
	}
	return 0;
}
