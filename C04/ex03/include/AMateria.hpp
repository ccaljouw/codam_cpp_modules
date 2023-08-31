/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 16:54:12 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/31 22:43:47 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AMATERIA_HPP_
# define _AMATERIA_HPP_

#include "../include/ICharacter.hpp"
#include <string>

class ICharacter;

class AMateria {
	
	public:

		AMateria(void);
		AMateria(std::string const& type);
		AMateria( AMateria const& rhs);
		AMateria const& operator=( AMateria const& rhs );
		virtual ~AMateria( void );

		std::string const & getType( void ) const;
		virtual AMateria* clone( void ) const = 0;
		virtual void use(ICharacter& target);

	protected:
		std::string	_type;
	
};

#endif
