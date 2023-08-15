/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/15 15:12:04 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/15 17:27:59 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{	
	{
		Weapon club = Weapon("nasty spiky thing");
		
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("nasty pointy thing");
		bob.attack();
	}
	{
		Weapon club = Weapon("nasty spiky thing");
		
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("nasty pointy thing");
		jim.attack();
	}
	return 0;
}