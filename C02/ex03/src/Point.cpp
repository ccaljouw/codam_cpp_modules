/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/25 15:09:37 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/27 19:19:32 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {
	return;
}

Point::Point(const Fixed& x, const Fixed& y) : _x(x), _y(y) {
	return;
}

Point::Point(const Point& rhs) : _x(rhs.getX()), _y(rhs.getY()) {
	return;
}

Point::~Point() {
	return;
}

Point& Point::operator=(const Point& rhs) {
	(void)rhs;
	return *this;
}

Fixed Point::getX( void ) const {
	return this->_x;
}

Fixed Point::getY( void ) const {
	return this->_y;
}