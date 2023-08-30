/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 13:24:18 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 13:36:20 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"
#include <iostream>

Brain::Brain( void ) {
	std::cout << "Default Brain constructor called" << std::endl;
	return;
}

Brain::Brain( Brain const& rhs ) {
	*this = rhs;
	std::cout << "Brain copy constructor called" << std::endl;
	return;	
}

Brain const& Brain::operator=(Brain const& rhs ) {
	(void)rhs;  //moet nog aangepast!
	std::cout << "Brain assignment constructor called" << std::endl;
	return *this;
}

Brain::~Brain( void ) {
	std::cout << "Default Brain destructor called" << std::endl;
	return;
}
