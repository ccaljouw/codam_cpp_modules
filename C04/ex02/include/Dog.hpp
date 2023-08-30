/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:52:14 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 16:04:47 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOG_HPP_
# define _DOG_HPP_

#include "../include/AAnimal.hpp"
#include "../include/Brain.hpp"

class Dog : public AAnimal
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
		Brain*		_brain;
};

#endif
