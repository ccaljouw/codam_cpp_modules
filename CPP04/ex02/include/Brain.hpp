/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 13:24:07 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/08 10:51:55 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BRAIN_HPP_
# define _BRAIN_HPP_

#include <string>

class Brain {
	
	public:

		Brain();
		Brain(Brain const& rhs);
		Brain const& operator=(Brain const& rhs);
		virtual ~Brain( void );
	
		std::string const*	getIdeas(void) const;
		void				setIdeas(std::string const* ideas);
		
	private:

		std::string 		_ideas[100];
};

#endif
