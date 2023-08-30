/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 16:54:12 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/30 18:49:52 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AMATERIA_HPP_
# define _AMATERIA_HPP_

#include "../include/ICharacter.hpp"
#include <string>

class AMateria {
	protected:
		std::string	_type;
	
	public:

		AMateria(void);
		AMateria(std::string const& type);
		AMateria( AMateria const& rhs);
		AMateria const& operator=( AMateria const& rhs );
		virtual ~AMateria( void );

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
