/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 15:57:17 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/28 18:24:55 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAGTRAP_HPP_
# define _FRAGTRAP_HPP_

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
	
		FragTrap( void );
		FragTrap( const std::string name );
		~FragTrap( void );

		void getStatus( void ) const;
		void attack( const std::string& target );
		void highFivesGuys(void);
	
	protected:
		
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif