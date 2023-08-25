/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/25 15:09:54 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/25 16:23:15 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _POINT_HPP_
# define _POINT_HPP_

#include "Fixed.hpp"

class Point {
	
	public:

		Point();
		Point(const Fixed& x, const Fixed& y);
		Point(const Point& rhs);
		~Point();
	
		Point& operator=(const Point& rhs);

		Fixed getX( void ) const;
		Fixed getY( void ) const;
		
		
	private:
		Fixed const _x;
		Fixed const _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif