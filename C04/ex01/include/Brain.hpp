/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 13:24:07 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/08/30 13:52:25 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BRAIN_HPP_
# define _BRAIN_HPP_

#include <string>

class Brain {
	
	public:

		Brain( void );
		Brain( Brain const& rhs );
		Brain const& operator=(Brain const& rhs );
		virtual ~Brain( void );
		
		std::string _ideas[100];
};

#endif
