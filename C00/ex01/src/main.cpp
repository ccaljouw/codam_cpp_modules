/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 18:57:40 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/01 16:13:07 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>
#include <iostream> //remove

int main()
{
	std::string	input;
	PhoneBook	phonebook;

	while (1)
	{
		std::cin >> input;
		if (!input.compare("ADD") || !input.compare("add"))
			phonebook.addContact();
		if (!input.compare("SEARCH") || !input.compare("search"))
			phonebook.printPhonebook();
		if (!input.compare("EXIT") || !input.compare("exit"))
			break;
	}
	return 0;
}