/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/03 13:50:57 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/13 18:53:42 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

#include <string>

class Zombie {
	
	public:
	
		Zombie( void );
		Zombie(std::string name);
		~Zombie( void );
		
		void announce( void ) const;
	
	private:
	
		std::string _name;
	
};

Zombie* newZombie( std::string name );
void 	randomChump( std::string name );

#endif