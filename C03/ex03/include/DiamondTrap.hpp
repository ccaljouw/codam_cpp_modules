/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 16:34:55 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/04 10:01:11 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DIAMONDTRAP_HPP_
# define _DIAMONDTRAP_HPP_

#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
	
		DiamondTrap( void );
		DiamondTrap( std::string name );
		~DiamondTrap( void );

		using ScavTrap::attack;
		
		void getStatus( void ) const;
		void whoAmI( void );
	
	private:

		std::string _name;
		using ScavTrap::_energyPoints;
		using FragTrap::_hitPoints;
		using FragTrap::_attackDamage;
		
};

#endif
