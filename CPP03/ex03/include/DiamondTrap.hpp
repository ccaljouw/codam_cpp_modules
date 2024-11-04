/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 16:34:55 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/06 12:19:06 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DIAMONDTRAP_HPP_
# define _DIAMONDTRAP_HPP_

#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
	
		DiamondTrap();
		DiamondTrap(std::string);
		DiamondTrap(const DiamondTrap& rhs);
		DiamondTrap& operator=(const DiamondTrap& rhs);
		~DiamondTrap();

		using ScavTrap::attack;
		
		void getStatus(void) const;
		void whoAmI(void);
	
	private:

		std::string _name;
		using ScavTrap::_energyPoints;
		using FragTrap::_hitPoints;
		using FragTrap::_attackDamage;
		
};

#endif
