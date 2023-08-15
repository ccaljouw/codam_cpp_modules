/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/15 15:16:37 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/15 18:31:28 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMANA_HPP_
# define _HUMANA_HPP_

#include "Weapon.hpp"
#include <string>

class HumanA {
	
	public:
		
		HumanA( std::string name, Weapon& myWeapon );
		~HumanA( void );

		void	attack( void ) const;
		
	private:

		std::string _name;
		Weapon&	_myWeapon;
};

#endif