/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 12:15:21 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/28 13:14:43 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_HPP_
# define _CLAPTRAP_HPP_

#include <string>

class ClapTrap {

	public:
		
		ClapTrap( void );
		ClapTrap( const std::string name );
		ClapTrap( const ClapTrap& rhs );
		ClapTrap& operator=( const ClapTrap& rhs );
		~ClapTrap( void );

		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
		
		void 			getStatus( void );
		unsigned int	getAttackDamage( void );
		
	private:
		
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	
};
#endif