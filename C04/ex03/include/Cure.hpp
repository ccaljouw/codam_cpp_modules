/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 17:13:38 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/31 14:32:51 by cariencaljo   ########   odam.nl         */
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

#endif
