/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/15 15:16:40 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/15 17:27:16 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMANB_HPP_
# define _HUMANB_HPP_

#include "Weapon.hpp"
#include <string>

class HumanB {
	
	public:
		
		HumanB( void );
		HumanB( std::string name );
		~HumanB( void );

		void	setWeapon( Weapon myWeapon );
		void	attack( void ) const;
		
	private:

		std::string _name;
		Weapon		_myWeapon;
};

#endif