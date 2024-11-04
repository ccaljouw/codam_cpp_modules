/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/03 16:48:01 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/15 20:11:03 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void leaks(void)
{
	system("leaks zombiehorde -q");
}

int main(void)
{	
	Zombie *first;
	int nr_zombies = 10;

	atexit(leaks);
	first = zombieHorde(nr_zombies, "hordeZombie");
	for(int i = 0; i < nr_zombies; i++)
		first[i].announce();
	delete [] first;
	return 0;
}