/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 15:57:17 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/28 16:08:17 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAGTRAP_HPP_
# define _FRAGTRAP_HPP_

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	
		FragTrap( void );
		FragTrap( const std::string name );
		~FragTrap( void );

		void attack( const std::string& target );
		void highFivesGuys(void);
};

#endif