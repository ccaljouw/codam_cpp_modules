/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ZombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/03 16:48:08 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/01 15:40:16 by ccaljouw      ########   odam.nl         */
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
