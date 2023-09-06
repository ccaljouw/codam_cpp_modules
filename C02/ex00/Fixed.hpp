/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:31:29 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/09/06 09:39:45 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
# define _FIXED_HPP_

class Fixed {
	
	public:

		Fixed();
		Fixed(const Fixed& rhs);
		Fixed&  operator=(const Fixed& rhs);
		~Fixed();
		
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
		
	private:

		int					_fixed;
		static const int	_bits = 8;
};

#endif