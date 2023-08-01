/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 18:51:55 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/01 15:39:09 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP_
#	define CONTACT_HPP_

#include <string>

class Contact {

public:
	
	Contact(void);
	~Contact(void);

	void		setContact(int i, std::string fn, std::string ln, std::string nn, std::string pn, std::string secr);
	void		printContact(void) const;
	int			getIndex(void) const;
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
		
private:

	int			_index;
	std::string _first_name;
	std::string _last_name;
	std::string	_nickname;
	std::string _phone_nr;
	std::string _secret;
};

#endif