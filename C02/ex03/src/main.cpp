/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:31:32 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/25 16:42:59 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main()
{
   /* Let us check whether the point P(10, 15) lies inside the triangle
      formed by A(0, 0), B(20, 0) and C(10, 30) */
   if (bsp(Point(), Point(Fixed(20), Fixed(0)), Point(Fixed(10), Fixed(30)), Point(Fixed(10), Fixed(15))))
     std::cout << "Inside";
   else
     std::cout <<"Not Inside";
  
   return 0;
}