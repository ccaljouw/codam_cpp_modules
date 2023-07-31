/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 15:03:27 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/07/31 16:34:52 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc > 1)
	{ 
		// for()
		// {
			std::string input = argv[1];
			std::transform(input.begin(), input.end(), input.begin(), toupper);
		// }
		std::cout << input << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}