/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:31:29 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/24 15:12:18 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
# define _FIXED_HPP_

#include <iostream>

class Fixed {
	
	public:

		Fixed( void );
		Fixed( const int num );
		Fixed( const float num );
		Fixed( const Fixed& rhs);
		~Fixed( void );
		
		Fixed&  operator=(const Fixed& rhs);
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
		
	private:

		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream& operator<<( std::ostream& o, Fixed const& i);

#endif