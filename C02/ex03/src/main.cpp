/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:31:32 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/27 16:58:37 by cariencaljo   ########   odam.nl         */
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
			   /           \		 P1(30, 10)
			  /				\		
			 /				 \		
			/				  \		
		   /				   \	
		  /			P2(15, 5)   \	
		 /						 \	
		/						  \	
       /						   \
	  /								\
A(0,0) -----P3(8, 0)----------------- C(30,0)
					P4(15, -3)
*/

int main( void )
{
	float	P1_x = 30;
	float	P1_y = 10;
	
	float	P2_x = 15;
	float	P2_y = 5;

	float	P3_x = 8;
	float	P3_y = 0;

	float	P4_x = 15;
	float	P4_y = -3;
	
	if (bsp(Point(Fixed(0), Fixed(0)), Point(Fixed(10), Fixed(15)), Point(Fixed(30), Fixed(0)), Point(Fixed(P1_x), Fixed(P1_y))))
    	std::cout << "P1 inside" << std::endl;
	else
		std::cout << "P1 not inside" << std::endl;
		
	if (bsp(Point(Fixed(0), Fixed(0)), Point(Fixed(10), Fixed(15)), Point(Fixed(30), Fixed(0)), Point(Fixed(P2_x), Fixed(P2_y))))
    	std::cout << "P2 inside" << std::endl;
	else
		std::cout <<"P2 not inside" << std::endl;

	if (bsp(Point(Fixed(0), Fixed(0)), Point(Fixed(10), Fixed(15)), Point(Fixed(30), Fixed(0)), Point(Fixed(P3_x), Fixed(P3_y))))
    	std::cout << "P3 inside" << std::endl;
	else
		std::cout <<"P3 not inside" << std::endl;

	if (bsp(Point(Fixed(0), Fixed(0)), Point(Fixed(10), Fixed(15)), Point(Fixed(30), Fixed(0)), Point(Fixed(P4_x), Fixed(P4_y))))
    	std::cout << "P3 inside" << std::endl;
	else
		std::cout <<"P3 not inside" << std::endl;

	return 0;
}
