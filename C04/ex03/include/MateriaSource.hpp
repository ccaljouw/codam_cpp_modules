/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 19:43:24 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/31 13:43:56 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MATERIASOURCE_HPP_
# define _MATERIASOURCE_HPP_

#include <string>
#include "../include/IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
	
		MateriaSource(void);
		MateriaSource(MateriaSource const& rhs);
		MateriaSource const& operator=(MateriaSource const& rhs);
		~MateriaSource(void);
		
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
	
	private:
		
		AMateria*	_inventory[4];
};

#endif
