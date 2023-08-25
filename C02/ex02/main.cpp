/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:31:32 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/25 15:01:10 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main( void ) { 
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "\n-------------------------------------------" << std::endl;
	std::cout << "Tests from subject" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "-------------------------------------------\n" << std::endl;
	
	std::cout << "\n-------------------------------------------" << std::endl;
	std::cout << "Increment decrement tests" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	a = 1;
	std::cout << "value a: " << a << " value b: " << b << std::endl;
	std::cout << "a++ " << a++ << "\t\ta_now: " << a << std::endl;
	std::cout << "a-- " << a-- << "\ta_now: " << a << std::endl;
	std::cout << "++a " << ++a << std::endl;
	std::cout << "--a " << --a << std::endl;
	std::cout << "a " << a << std::endl;
	
	std::cout << "\nvalue a: " << a << " value b: " << b << std::endl;
	
	std::cout << "max(a, b): " << Fixed::max( a, b ) << std::endl;
	std::cout << "min(a, b): " << Fixed::min( a, b ) << std::endl;
	std::cout << "max(b, a): " << Fixed::max( b, a ) << std::endl;
	std::cout << "min(b, a): " << Fixed::min( b, a ) << std::endl;
	std::cout << "-------------------------------------------\n" << std::endl;

	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "Tests arithmic operators" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	
	std::cout << "value a: " << a << " value b: " << b << std::endl;

	std::cout << "a + b: " << (a + b) << std::endl;
	std::cout << "b + a: " << (b + a) << std::endl;
	std::cout << "a - b: " << (a - b) << std::endl;
	std::cout << "b - a: " << (b - a) << std::endl;
	std::cout << "a * b: " << (a * b) << std::endl;
	std::cout << "b * a: " << (b * a) << std::endl;
	std::cout << "a / b: " << (a / b) << std::endl;
	std::cout << "b / a: " << (b / a) << std::endl;
	std::cout << "-------------------------------------------\n" << std::endl;

	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "Tests compaison operators" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	
	std::cout << "value a: " << a << " value b: " << b << std::endl;
	
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "b > a: " << (b > a) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "b >= a: " << (b >= a) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "b < a: " << (b < a) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "b <= a: " << (b <= a) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	
	a = b;
	std::cout << "\nvalue a: " << a << " value b: " << b << std::endl;
	
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << "b == a: " << (b == a) << std::endl;
	std::cout << "b != a: " << (b != a) << std::endl;
	std::cout << "-------------------------------------------\n" << std::endl;

	return 0; 
}