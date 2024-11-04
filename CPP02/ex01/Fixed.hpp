/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:31:29 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/05 13:28:34 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
# define _FIXED_HPP_

#include <iostream>

class Fixed {
	
	public:

		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed& rhs);
		Fixed&  operator=(const Fixed& rhs);
		~Fixed();
		
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
		float	toFloat(void) const;
		int		toInt(void) const;
		
		
	private:

		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& o, Fixed const& i);

#endif