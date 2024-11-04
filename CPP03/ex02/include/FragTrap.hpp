/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/28 15:57:17 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/06 12:11:38 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAGTRAP_HPP_
# define _FRAGTRAP_HPP_

#include "../include/ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	
		FragTrap();
		FragTrap(const std::string);
		FragTrap(const FragTrap& rhs);
		FragTrap& operator=(const FragTrap& rhs);
		~FragTrap();

		void attack( const std::string& target );
		void highFivesGuys(void);
};

#endif
