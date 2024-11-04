/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/02 16:09:39 by cariencaljo   #+#    #+#                 */
/*   Updated: 2024/08/04 09:59:31 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void leaks(void) {
	std::cout << "*********************************" << std::endl;
	system("leaks form -q");
	std::cout << "*********************************" << std::endl;
}

int main() {
  atexit(leaks);
  try {
    std::cout << "---------------------------------" << std::endl;
    Bureaucrat best("Best", 1);
    std::cout << best << std::endl;

    Bureaucrat worst("Worst", 150);
    std::cout << worst << std::endl;

    Bureaucrat middle("Middle", 75);
    std::cout << middle << std::endl;
    
    std::cout << "---------------------------------" << std::endl;
    Form importantForm("Important Form", 1, 1);
    std::cout << importantForm << std::endl;

    Form rubbishForm("Rubbish Form", 150, 75);
    std::cout << rubbishForm << std::endl;

    Form randomForm("Random Form", 76, 74);
    std::cout << randomForm << std::endl;

    std::cout << "---------------------------------" << std::endl;
    std::cout << "INCORRECT CONSTRUCTION OF FORMS\n" << std::endl;
    try {
      Form tooHigh1("TooHigh", 0, 1);
      std::cout << tooHigh1 << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }

    try {
      Form tooHigh2("TooHigh2", 1, 0);
      std::cout << tooHigh2 << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }

    try {
      Form tooLow1("TooLow", 151, 150);
      std::cout << tooLow1 << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }

    try {
      Form tooLow2("TooLow2", 150, 151);
      std::cout << tooLow2 << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;
    
    std::cout << "FORM CANNOT BE SIGNED\n" << std::endl;
    std::cout << randomForm << std::endl;
    std::cout << worst << std::endl;
    try {
      randomForm.beSigned(worst);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    try {
      worst.signForm(randomForm);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;

    std::cout << "SIGNING FORMS\n" << std::endl;
    best.signForm(importantForm);
    best.signForm(randomForm);
    best.signForm(rubbishForm);

    middle.signForm(randomForm);
    middle.signForm(rubbishForm);
    
    worst.signForm(rubbishForm);
    std::cout << "---------------------------------" << std::endl;
    
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
