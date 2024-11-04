/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 13:24:18 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/08 10:52:07 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Default Brain constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
		this->_ideas[i] = std::string();
	return;
}

Brain::Brain(Brain const& rhs) {
	*this = rhs;
	std::cout << "Brain copy constructor called" << std::endl;
	return;
}

Brain const& Brain::operator=(Brain const& rhs) {
	this->setIdeas(rhs.getIdeas());
	std::cout << "Brain assignment constructor called" << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "Default Brain destructor called" << std::endl;
	return;
}

std::string const*	Brain::getIdeas(void) const {
	return this->_ideas;
}

void	Brain::setIdeas(std::string const* ideas) {
	for(int i = 0; i < 100; i++)
		this->_ideas[i] = ideas[i];
}
