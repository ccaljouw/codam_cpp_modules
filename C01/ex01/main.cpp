/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/03 16:48:01 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/15 14:57:57 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void leaks(void)
{
	system("leaks zombiehorde");
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