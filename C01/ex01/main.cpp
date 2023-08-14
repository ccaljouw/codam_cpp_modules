/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/03 16:48:01 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/13 18:59:46 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{	
	Zombie *first;
	int nr_zombies = 8;

	first = zombieHorde(nr_zombies, "hordeZombie");
	for(int i = 0; i < nr_zombies; i++)
		first[i].announce();
	deleteZombieHorde(nr_zombies, first);
	return 0;
}