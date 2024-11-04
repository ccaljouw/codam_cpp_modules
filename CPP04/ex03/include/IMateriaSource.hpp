/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   IMateriaSource.hpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 19:43:24 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/08 12:59:09 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _IMATERIASOURCE_HPP_
# define _IMATERIASOURCE_HPP_

#include <string>
#include "../include/AMateria.hpp"

class IMateriaSource
{
	public:
		IMateriaSource( void );
		virtual ~IMateriaSource( void );
		virtual void	  learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
		virtual void	  printInventory(void) const = 0;
};

#endif
