/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/03 13:50:33 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/13 16:23:55 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
	Zombie *newzombie;
	
	newzombie = new Zombie(name);
	return newzombie;
}