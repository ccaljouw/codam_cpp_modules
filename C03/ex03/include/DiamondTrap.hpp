/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 16:34:55 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/28 18:19:05 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DIAMONDTRAP_HPP_
# define _DIAMONDTRAP_HPP_

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
		unsigned int	_energyPoints;
		unsigned int	_hitPoints;
		unsigned int	_attackDamage;
		
};

#endif
