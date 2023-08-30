/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 10:51:35 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 16:04:02 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AAnimal_HPP_
# define _AAnimal_HPP_

#include <string>

class AAnimal {
	
	public:
		AAnimal( void );
		AAnimal( std::string type );
		AAnimal( AAnimal const& rhs);
		AAnimal const& operator=( AAnimal const& rhs);
		virtual ~AAnimal( void );

		std::string 		getType( void ) const;
		virtual void		makeSound( void ) const = 0;
		
	protected:
		 
		 std::string	_type;
};

#endif
