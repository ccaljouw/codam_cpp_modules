/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:51:35 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/06 13:55:05 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ANIMAL_HPP_
# define _ANIMAL_HPP_

#include <string>

class Animal {
	
	public:
		Animal();
		Animal(Animal const& rhs);
		Animal const& operator=(Animal const& rhs);
		virtual ~Animal();

		virtual std::string getType(void) const;
		virtual void		makeSound(void) const;
		
	protected:
		 
		 std::string	_type;
};

#endif
