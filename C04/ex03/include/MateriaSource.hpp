/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 19:43:24 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/30 19:50:49 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MATERIASOURCE_HPP_
# define _MATERIASOURCE_HPP_

#include <string>
#include "../include/AMateria.hpp"

class MateriaSource
{
	public:
	
		MateriaSource(std::string type);
		MateriaSource(MateriaSource const& rhs);
		MateriaSource const& operator=(MateriaSource const& rhs);
		~MateriaSource(void);
		
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
	
	private:
		
		AMateria*	_inventory[4];
};

#endif
