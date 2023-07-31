/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 15:03:27 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/07/31 19:04:18 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		for(int i = 1; i < argc; i++)
		{
			std::string input(argv[i]);
			std::transform(input.begin(), input.end(), input.begin(), toupper);
			std::cout << input;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
