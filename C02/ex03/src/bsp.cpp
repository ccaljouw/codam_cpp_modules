/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bsp.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/25 15:09:32 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/25 16:36:59 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

float absolute(float n) {
	return n < 0 ? (n * -1) : n; 	
}

float	area(Point const p1, Point const p2, Point const p3) {
	float v1 = p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat());
	float v2 = p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat());
	float v3 = p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat());
	return absolute((v1 + v2 + v3) / 2.0);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	float A = area(a, b, c);
	float a1 = area(point, b, c);
	float a2 = area(point, a, c);
	float a3 = area(point, a, b);
	return (A == a1 + a2 + a3);
}

// • a, b, c: The vertices of our beloved triangle.
// • point: The point to check.
// • Returns: True if the point is inside the triangle. False otherwise. Thus, 
//   if the point is a vertex or on edge, it will return False.