/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 17:13:38 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/08 13:08:02 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CURE_HPP_
#define _CURE_HPP_

#include "../include/AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure( void );
		Cure(std::string const& type);
		Cure( Cure const& rhs);
		Cure const& operator=( Cure const& rhs );
		~Cure( void );

		Cure* clone() const;
		void use(ICharacter& target);

	private:
};

std::ostream& operator<<(std::ostream& o, Cure const& i);

#endif
