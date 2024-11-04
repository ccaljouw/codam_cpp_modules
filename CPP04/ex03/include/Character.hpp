/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 17:07:21 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/08 13:10:28 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHARACTER_HPP_
# define _CHARACTER_HPP_

#include "../include/ICharacter.hpp"
#include <iostream>

class Character : public ICharacter
{
	public:

		Character( void );
		Character( std::string name );
		Character( Character const& rhs );
		Character const& operator=( Character const& rhs );
		~Character( void );

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void printInventory(void) const;
		
	private:
	
		std::string	_name;
		AMateria*	_inventory[4];
		AMateria**	_oldInventory;
		int			_oldInventorySize;
		void		addToOldInventory(AMateria* m);
	
};
#endif
