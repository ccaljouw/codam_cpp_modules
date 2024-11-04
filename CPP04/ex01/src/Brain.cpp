/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 13:24:18 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/08 12:07:52 by ccaljouw      ########   odam.nl         */
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
	for(int i = 0; i < 100; i++)
		this->_ideas[i] = rhs.getIdeas()[i];
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

void	Brain::setIdea(const std::string ideas) {
	int i;
	for(i = 0; i < 100; i++) {
		if(this->_ideas[i].empty()) {
			this->_ideas[i] = ideas;
			break;
		}
	}
	if (i == 100)
		std::cout << "Sorry brain is full...." << std::endl;
}

void	Brain::printIdeas(void) const {
	for(int i = 0; i < 100; i++) {
		if(!this->_ideas[i].empty())
			std::cout << this->_ideas[i] << std::endl;
		else
			break;
	}
	return;
}

void	Brain::copyIdeas(Brain* rhs) {
	for(int i = 0; i < 100; i++)
		this->_ideas[i] = rhs->getIdeas()[i];
}
