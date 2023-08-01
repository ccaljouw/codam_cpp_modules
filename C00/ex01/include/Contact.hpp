/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 18:51:55 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/01 19:12:33 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP_
# define CONTACT_HPP_

#include <string>

class Contact {

public:
	
	int			index;
	std::string first_name;
	std::string last_name;
	std::string	nickname;
	
	Contact(void);
	~Contact(void);

	void		setContact(int i, std::string fn, std::string ln, std::string nn, std::string pn, std::string secr);
	int			printContact(void) const;
		
private:

	std::string _phone_nr;
	std::string _secret;
};

#endif