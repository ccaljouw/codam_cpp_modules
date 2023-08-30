/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 17:12:56 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/30 17:16:46 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ICE_HPP_
#define _ICE_HPP_

#include "../include/AMateria.hpp"

class Ice : AMateria
{
	public:
		Ice(std::string const& type);
		Ice( Ice const& rhs);
		Ice const& operator=( Ice const& rhs );
		~Ice( void );

		Ice* clone() const;
		void use(ICharacter& target);

	private:
};

#endif
