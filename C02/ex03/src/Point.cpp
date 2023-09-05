/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/25 15:09:37 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/05 14:37:15 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {
	return;
}

Point::Point(const float x, const float y)  : _x(Fixed(x)), _y(Fixed(y))  {
	return;
}

Point::Point(const Point& rhs)  : _x(rhs.getX()), _y(rhs.getY())  {
	return;
}

Point& Point::operator=(const Point& rhs) {
	(void)rhs;
	return *this;
}

Point::~Point() {
	return;
}

Fixed Point::getX(void) const {
	return this->_x;
}

Fixed Point::getY(void) const {
	return this->_y;
}

std::ostream &operator<<(std::ostream& o, Point const& i) {
	o << "(" << i.getX().toFloat() << ", " << i.getY().toFloat() << ")";
	return o;	
};