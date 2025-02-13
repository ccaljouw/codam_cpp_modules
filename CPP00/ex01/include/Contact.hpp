/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 18:51:55 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/01 09:53:02 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_HPP_
# define CONTACT_HPP_

#include <string>
#include <iostream>
#include <iomanip>

class Contact {

public:
	
	int			index;
	std::string first_name;
	std::string last_name;
	std::string	nickname;
	
	Contact(void);
	~Contact(void);

	void		setContact(int i);
	int			printContact(void) const;
		
private:

	std::string _phone_nr;
	std::string _secret;
	std::string _getInput(std::string str);
};

#endif