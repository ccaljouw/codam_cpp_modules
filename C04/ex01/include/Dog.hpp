/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:52:14 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/08 11:44:41 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOG_HPP_
# define _DOG_HPP_

#include "../include/Animal.hpp"
#include "../include/Brain.hpp"

class Dog : public Animal
{
	public:
	
		Dog();
		Dog(Dog const& rhs);
		Dog const& operator=(Dog const& rhs);
		~Dog();

		void		makeSound(void) const;
		std::string getType(void) const;
		Brain*		getBrain(void) const;

	private:
		
		std::string _type;
		Brain*		_brain;
};

#endif
