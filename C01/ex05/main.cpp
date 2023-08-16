/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/16 15:14:53 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/16 16:16:18 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harry;

	harry.complain("DEBUG");
	harry.complain("INFO");
	harry.complain("WARNING");
	harry.complain("ERROR");
	harry.complain("random");
	return 0;
}