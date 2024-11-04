/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/15 15:17:48 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/01 15:43:40 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WEAPON_HPP_
# define _WEAPON_HPP_

#include <string>

class Weapon {
	
	public:

		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		
		std::string const &	getType(void) const;
		void	setType(std::string str);
	
	private:
	
		std::string _type;
};

#endif