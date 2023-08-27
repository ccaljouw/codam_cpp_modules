/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:31:32 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/27 15:41:32 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main( void )
{
	float	point1_x = 20;
	float	point1_y = 15;
	float	point2_x = 10;
	float	point2_y = 5;
	
	if (bsp(Point(Fixed(0), Fixed(0)), Point(Fixed(10), Fixed(30)), Point(Fixed(20), Fixed(0)), Point(Fixed(point1_x), Fixed(point1_y))))
    	std::cout << "P1 inside" << std::endl;
	else
		std::cout << "P1 not inside" << std::endl;
	if (bsp(Point(Fixed(0), Fixed(0)), Point(Fixed(10), Fixed(30)), Point(Fixed(20), Fixed(0)), Point(Fixed(point2_x), Fixed(point2_y))))
    	std::cout << "P2 inside" << std::endl;
	else
		std::cout <<"P2 not inside" << std::endl;

	return 0;
}

    /*
	          B(10,30)
                / \
               /   \
              /     \	P1 (20 ,15)
             /       \ 
            /P2(10, 5)\
     A(0,0) ----------- C(20,0)
	*/