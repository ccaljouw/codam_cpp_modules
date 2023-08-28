/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 13:40:52 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/28 15:47:55 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCAVTRAP_HPP_
# define _SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
	
		ScavTrap( void );
		ScavTrap( const std::string name );
		~ScavTrap( void );

		void attack( const std::string& target );

	private:
};

#endif