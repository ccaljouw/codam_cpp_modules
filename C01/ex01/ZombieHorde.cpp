/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ZombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/03 16:48:08 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/13 18:55:06 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombieHorde = new Zombie[N];
	
	for (int i = 0; i < N; i++)
		zombieHorde[i].setName(name + "_" + std::to_string(i + 1));
	return zombieHorde;
}

void	deleteZombieHorde( int N, Zombie* first )
{
	for(int i = 0; i < N; i++)
		first[i].~Zombie();
	return;
}
