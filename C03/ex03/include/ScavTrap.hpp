/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 13:40:52 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/02 11:50:08 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCAVTRAP_HPP_
# define _SCAVTRAP_HPP_

#include "../include/ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
	
		ScavTrap(void);
		ScavTrap(const std::string name);
		~ScavTrap(void);

		void getStatus(void) const;
		void attack(const std::string& target);
		void guardGate(void);

		protected:
			
			std::string		_name;
			unsigned int	_hitPoints;
			unsigned int	_energyPoints;
			unsigned int	_attackDamage;
};

#endif
