/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 18:51:58 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/01 09:53:05 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP_
# define PHONEBOOK_HPP_

#include "Contact.hpp"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);
	
	void		addContact(void);
	void		searchPhonebook(void) const;
	
private:

	int			_nr_contacts;
	Contact		_contacts[8];
	
	Contact		_getContact(int i) const;
	void		_printColumn(std::string str) const;
	void		_printPhonebook(void) const;
};

#endif