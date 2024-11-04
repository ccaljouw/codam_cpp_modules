/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:52:10 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/08 10:52:55 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAT_HPP_
# define _CAT_HPP_

#include "../include/AAnimal.hpp"
#include "../include/Brain.hpp"

class Cat : public AAnimal
{
	public:
	
		Cat();
		Cat(Cat const& rhs);
		Cat const& operator=(Cat const& rhs);
		~Cat();

		void			makeSound(void) const;
		std::string		getType(void) const;
		Brain const*	getBrain(void) const;
	
	private:
		
		std::string _type;
		Brain*		_brain;
};

#endif