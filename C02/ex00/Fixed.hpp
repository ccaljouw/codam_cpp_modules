/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:31:29 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/15 08:34:46 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
# define _FIXED_HPP_

class Fixed {
	
	public:

		Fixed( void );
		Fixed( const Fixed& rhs);
		Fixed&  operator=(const Fixed& rhs);
		~Fixed( void );
		
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
		
	private:

		int					_fixed;
		static const int	_bits = 8;
};

#endif