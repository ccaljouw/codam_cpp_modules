/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongWrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:52:10 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 13:06:20 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WrongCat_HPP_
# define _WrongCat_HPP_

#include "../include/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	
		WrongCat( void );
		WrongCat( std::string type );
		WrongCat( WrongCat const& rhs);
		WrongCat const& operator=( WrongCat const& rhs);
		~WrongCat( void );

		void	makeSound( void ) const;
	
	private:
		
		std::string _type;
};

#endif
