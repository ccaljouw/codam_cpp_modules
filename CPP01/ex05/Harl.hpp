/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/16 15:15:37 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/01 15:48:49 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HARL_HPP_
# define _HARL_HPP_

#include <string>

class Harl {

	public:

		Harl(void);
		~Harl(void);
		
		void	complain(std::string level);
		
	private:
	
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif