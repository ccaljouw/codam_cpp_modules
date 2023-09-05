/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:31:32 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/05 14:54:52 by cariencaljo   ########   odam.nl         */
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

int main( void )
{
	Point	A;
	Point	B(15, 15);
	Point	C(30, 0);
	Point	P[4] = {Point(30, 10), Point(15, 5), Point(8, 0), Point(15, -3)
	};
	
	for(int i = 0; i < 4; i++)
	{
		if (bsp(A, B, C, P[i]))
    		std::cout << "\nP" << P[i] << " inside t:";
		else
			std::cout << "\nP" << P[i]<< " not inside t";
		std::cout << A << ", " << B << ", " << C << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
