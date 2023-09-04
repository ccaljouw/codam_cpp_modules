/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:52:14 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 12:51:57 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOG_HPP_
# define _DOG_HPP_

#include "../include/Animal.hpp"

class Dog : public Animal
{
	public:
	
		Dog( void );
		Dog( std::string type );
		Dog( Dog const& rhs);
		Dog const& operator=( Dog const& rhs);
		~Dog( void );

		void	makeSound( void ) const;

	private:
		
		std::string _type;
};

#endif