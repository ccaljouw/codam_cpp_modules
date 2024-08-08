/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaljouw <ccaljouw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:09:39 by cariencaljo       #+#    #+#             */
/*   Updated: 2024/08/08 12:55:40 by ccaljouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void leaks(void) {
	std::cout << "*********************************" << std::endl;
	system("leaks type -q");
	std::cout << "*********************************" << std::endl;
}

// static void test(std::string str);
// static void testInput(void);

int main(int argc, char *argv[])
{
    atexit(leaks);
    if (argc == 2) {
        std::cout << argv[0] << ", " << argv[1] << std::endl;
        // do something
    }
    else {
        std::cout << "No input provided, running standard tests" << std::endl;
        // testInput();
    }
}

// static void test(std::string str) {
//     std::cout << "Testing: " << str << std::endl;
//     // do something
//     std::cout << std::endl;
// }

// static void testInput(void) {
//     // write tests
// }