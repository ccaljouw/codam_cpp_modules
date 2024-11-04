/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:52:10 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/06 13:55:52 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAT_HPP_
# define _CAT_HPP_

#include "../include/Animal.hpp"

class Cat : public Animal
{
	public:
	
		Cat();
		Cat(Cat const& rhs);
		Cat const& operator=(Cat const& rhs);
		~Cat();

		void		makeSound(void) const;
		std::string getType(void) const;
	
	private:
		
		std::string _type;
};

#endif
