/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bsp.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/25 15:09:32 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/06 09:39:05 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"
#include <cmath>

float absolute(float n) {
	return n < 0 ? (n * -1) : n; 	
}

// calculate area with Heron's formula
float	area(Point const& p1, Point const& p2, Point const& p3) {
	float d1 = p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat());
	float d2 = p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat());
	float d3 = p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat());
	return absolute((d1 + d2 + d3) / 2.0);
}

// if the given point is inside the triangle the total area will be equal to the 
// 3 triangles the given point forms with the other coordinates. 
// If one of the 3 areas with point is 0 this means the point is on one of the lines of the triangle.
bool bsp( Point const a, Point const b, Point const c, Point const point) {
	float A = area(a, b, c);
	float a1 = area(point, b, c);
	float a2 = area(point, a, c);
	float a3 = area(point, a, b);
	if (!a1 || !a2 || !a3)
		return 0;
	return (A == a1 + a2 + a3);
}
