/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:31:29 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/08/25 14:56:29 by cariencaljo   ########   odam.nl         */
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
		
		bool	operator>(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;

		Fixed	operator+(const Fixed& rhs) const;
		Fixed	operator-(const Fixed& rhs) const;
		Fixed	operator*(const Fixed& rhs) const;
		Fixed	operator/(const Fixed& rhs) const;

		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
		static Fixed&	min(Fixed& a, Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
		
	private:

		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream& operator<<( std::ostream& o, Fixed const& i);

#endif