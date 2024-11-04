/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/25 15:09:54 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/05 14:54:28 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _POINT_HPP_
# define _POINT_HPP_

#include "../include/Fixed.hpp"

class Point {
	
	public:

		Point();
		Point(const float, const float);
		Point(const Point& rhs);
		Point& operator=(const Point& rhs);
		~Point();
	
		Fixed	getX(void) const;
		Fixed	getY(void) const;
		
	private:
	
		const Fixed _x;
		const Fixed _y;
};

std::ostream &operator<<(std::ostream& o, Point const& i);

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif