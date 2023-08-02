/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 18:51:58 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/01 20:15:41 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
# define PHONEBOOK_HPP_

#include "Contact.hpp"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);
	
	void	addContact(void);
	void	searchPhonebook(void) const;
	
private:

	int		_nr_contacts;
	Contact	_contacts[8];
	
	Contact	getContact(int i) const;
	void	printPhonebook(void) const;
};

#endif