/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 17:12:56 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/08 13:08:12 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ICE_HPP_
#define _ICE_HPP_

#include "../include/AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice( void );
		Ice(std::string const& type);
		Ice( Ice const& rhs);
		Ice const& operator=( Ice const& rhs );
		~Ice( void );

		Ice* clone() const;
		void use(ICharacter& target);

	private:
};

std::ostream& operator<<(std::ostream& o, Ice const& i);

#endif
