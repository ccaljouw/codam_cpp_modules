/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:52:10 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 13:31:40 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAT_HPP_
# define _CAT_HPP_

#include "../include/Animal.hpp"
#include "../include/Brain.hpp"

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
		Brain*		_brain;
		
};

#endif
