/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:31:32 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/27 19:18:13 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
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
A(0,0) -----P3(8, 0)----------------- C(30,0)			P3 inside
					P4(15, -3)							P4 not inside
*/

int main( void )
{
	Point	A;
	Point	B(Fixed(15), Fixed(15));
	Point	C(Fixed(30), Fixed());
	Point	P[4] = {
		Point(Fixed(30), Fixed(10)), 
		Point(Fixed(15.0f), Fixed(5.0f)), 
		Point(Fixed(8), Fixed(0)), 
		Point(Fixed(15.0f), Fixed(-3.0f))
	};
	
	for(int i = 0; i < 4; i++)
	{
		if (bsp(A, B, C, P[i]))
    		std::cout << "P" << i + 1 << " inside" << std::endl;
		else
			std::cout << "P" << i + 1 << " not inside" << std::endl;
	}
	return 0;
}
