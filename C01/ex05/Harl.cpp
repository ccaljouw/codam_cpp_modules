/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/16 15:15:28 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/22 12:26:40 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

	Harl::Harl( void ) {
		return;
	}
	
	Harl::~Harl( void ) {
		return;
	}
	
	void	Harl::complain( std::string level ) {
		
		std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
		
		for (int i = 0; i < 4; i++) {
			if (levels[i] == level)
				(this->*ptr[i])();
		}
		return;
	}

	void	Harl::debug( void ) {
		std::cout << "[ DEBUG ]" << std::endl;
		std::cout << "I am really good at debugging." << std::endl;
		return;
	}
	
	void	Harl::info( void ) {
		std::cout << "[ INFO ]" << std::endl;
		std::cout << "I have so much information,  I'm an oracle." << std::endl;
		return;
	}
	
	void	Harl::warning( void ) {
		std::cout << "[ WARNING ]" << std::endl;
		std::cout << "I do not like it when people don't listen to me." << std::endl;
		return;
	}
	
	void	Harl::error( void ) {
		std::cout << "[ ERROR ]" << std::endl;
		std::cout << "Errorrrrrr!!!!" << std::endl;
		return;
	}