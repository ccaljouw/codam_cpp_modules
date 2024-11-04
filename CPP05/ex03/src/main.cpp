/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/02 16:09:39 by cariencaljo   #+#    #+#                 */
/*   Updated: 2024/08/04 17:12:02 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

void leaks(void) {
	std::cout << "*********************************" << std::endl;
	system("leaks intern -q");
	std::cout << "*********************************" << std::endl;
}

int main(int argc, char **argv) {
  atexit(leaks);
  
  if (argc != 2) {
    std::cout << "Please provide form name" << std::endl;
    return 1;
  } else {
    try {
      Intern intern;
      AForm *form = intern.makeForm(argv[1], "target");
      std::cout << *form << std::endl;
      delete form;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    
  }
}
