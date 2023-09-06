/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:31:32 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/06 11:36:57 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"
#include <iostream>

/*
					B(15,15)
					/ \
				   /   \
				  /     \
				 /       \ 
				/		  \
			   /           \		 P1(30, 10)			P1 not inside
			  /				\		
			 /				 \		
			/				  \		
		   /				   \	
		  /			P2(15, 5)   \						P2 inside
		 /						 \	
		/						  \	
       /						   \
	  /								\
A(0,0) -----P3(8, 0)----------------- C(30,0)			P3 not inside
					P4(15, -3)							P4 not inside
*/

void leaks(void) {
	std::cout << "--------------------------------" << std::endl;
	system("leaks bsp -q");
	std::cout << "--------------------------------" << std::endl;	
}

int main( void )
{
	atexit(leaks);
	{
		Point	A;
		Point	B(0, 1);
		Point	C(1, 0);
		Point	P[5] = {Point(1, 1), Point(.1, .1), Point(.49, .49), Point(.5, .5), Point(0, 0)};
		
		std::cout << "triangle " << A << ", " << B << ", " << C << std::endl;
		for(int i = 0; i < 5; i++)
			std::cout << bsp(A, B, C, P[i]) << ":\t" << P[i] << std::endl;
		std::cout << std::endl;
	}
	{
		Point	A(1, 2);
		Point	B(3, 4);
		Point	C(5, 3);
		Point	P[4] = {Point(1, 1), Point(3, 3.99), Point(3, 4), Point(3, 3.5)};
		
		std::cout << "triangle " << A << ", " << B << ", " << C << std::endl;
		for(int i = 0; i < 4; i++)
			std::cout << bsp(A, B, C, P[i]) << ":\t" << P[i] << std::endl;
		std::cout << std::endl;
	}
	{
		Point	A;
		Point	B(15, 15);
		Point	C(30, 0);
		Point	P[4] = {Point(30, 10), Point(15, 5), Point(8, 0), Point(15, -3)};
		
		std::cout << "triangle " << A << ", " << B << ", " << C << std::endl;
		for(int i = 0; i < 4; i++)
			std::cout << bsp(A, B, C, P[i]) << ":\t" << P[i] << std::endl;
		std::cout << std::endl;
	}
	return 0;
}
