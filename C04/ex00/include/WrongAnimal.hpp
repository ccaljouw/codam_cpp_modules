/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:51:35 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 13:16:11 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WRONGANIMAL_HPP_
# define _WRONGANIMAL_HPP_

#include <string>

class WrongAnimal {
	
	public:
		WrongAnimal( void );
		WrongAnimal( std::string type );
		WrongAnimal( WrongAnimal const& rhs);
		WrongAnimal const& operator=( WrongAnimal const& rhs);
		virtual ~WrongAnimal( void );

		std::string 	getType( void ) const;
		void			makeSound( void ) const;
		
	protected:
		 
		 std::string	_type;
};

#endif
