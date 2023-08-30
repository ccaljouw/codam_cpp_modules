/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:52:10 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 12:51:48 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAT_HPP_
# define _CAT_HPP_

#include "../include/Animal.hpp"

class Cat : public Animal
{
	public:
	
		Cat( void );
		Cat( std::string type );
		Cat( Cat const& rhs);
		Cat const& operator=( Cat const& rhs);
		~Cat( void );

		void	makeSound( void ) const;
	
	private:
		
		std::string _type;
};

#endif
