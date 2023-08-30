/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:51:35 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 13:05:42 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ANIMAL_HPP_
# define _ANIMAL_HPP_

#include <string>

class Animal {
	
	public:
		Animal( void );
		Animal( std::string type );
		Animal( Animal const& rhs);
		Animal const& operator=( Animal const& rhs);
		virtual ~Animal( void );

		std::string 		getType( void ) const;
		virtual void		makeSound( void ) const;
		
	protected:
		 
		 std::string	_type;
};

#endif
