/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 13:24:18 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 15:48:18 by cariencaljo   ########   odam.nl         */
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
	this->setIdeas(rhs.getIdeas());
	std::cout << "Brain assignment constructor called" << std::endl;
	return *this;
}

Brain::~Brain( void ) {
	std::cout << "Default Brain destructor called" << std::endl;
	return;
}

std::string const*	Brain::getIdeas( void ) const {
	return this->_ideas;
}

void	Brain::setIdeas( std::string const* ideas ) {
	std::copy(ideas, ideas + 100, this->_ideas);
}
