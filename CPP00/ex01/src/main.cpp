/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 18:57:40 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/03 13:38:32 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string	input;
	PhoneBook	phonebook;
	
	std::cout << std::endl;
	std::cout << std::setw(75) << std::setfill('-') << "\n";
	std::cout << "This is your phonebook, what do you want to do?" << std::endl << std::endl;
	while (1)
	{
		std::cout << std::setw(75) << std::setfill('-') << "-" << std::endl;
		std::cout << "Type 'ADD' to add a contact to your phonebook" << std::endl;
		std::cout << "Type 'SEARCH' to search contacts in your phonebook" << std::endl;
		std::cout << "Type 'EXIT' to leave this program, all your contacts will be destroyed" << std::endl;
		std::cout << std::setw(75) << std::setfill('-') << "-" << "\n" << std::endl;
		if (!std::getline(std::cin, input))
		{
			std::cout << "Ctrl+D: exiting program" << std::endl;
			exit(0);
		}
		if (!input.compare("ADD"))
			phonebook.addContact();
		if (!input.compare("SEARCH"))
			phonebook.searchPhonebook();
		if (!input.compare("EXIT"))
			break;
	}
	return 0;
}