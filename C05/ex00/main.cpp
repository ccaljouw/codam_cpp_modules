/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/02 16:09:39 by cariencaljo   #+#    #+#                 */
/*   Updated: 2024/08/04 09:42:22 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void leaks(void) {
	std::cout << "*********************************" << std::endl;
	system("leaks bureaucrat -q");
	std::cout << "*********************************" << std::endl;
}

int main() {
  atexit(leaks);
  std::cout << "---------------------------------" << std::endl;
  try {
    Bureaucrat best("Best", 1);
    std::cout << best << std::endl;

    Bureaucrat worst("Worst", 150);
    std::cout << worst << std::endl;

    Bureaucrat middle("Middle", 75);
    std::cout << middle << std::endl;
  std::cout << "---------------------------------" << std::endl;
    try {      
      std::cout << "CONSTRUCTION WITH VALUE THAT IS TOO HIGH\n" << std::endl;
      Bureaucrat tooGood("TooGood", 0);
    } catch(const std::exception& e){
      std::cout << e.what() << std::endl;
    }
  std::cout << "---------------------------------" << std::endl;
    try {
      std::cout << "CONSTRUCTION WITH VALUE THAT IS TOO LOW\n" << std::endl;
      Bureaucrat tooBad("TooBad", 151);
      std::cout << tooBad << std::endl;
    } catch(const std::exception& e){
      std::cout << e.what() << std::endl;
    }
  std::cout << "---------------------------------" << std::endl;
    try{
      std::cout << middle << std::endl;
      middle.addGrade();
      std::cout << middle << std::endl;
      middle.subGrade();
      std::cout << middle << std::endl;
    } catch(const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  std::cout << "---------------------------------" << std::endl;
    try {
      std::cout << best << std::endl;
      std::cout << "ADDING TO MIN VALUE\n" << std::endl;
      best.addGrade();
    } catch(const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  std::cout << "---------------------------------" << std::endl;
    try {
      std::cout << worst << std::endl;
      std::cout << "SUBTRACTING FROM MAX VALUE\n" << std::endl;
      worst.subGrade();
    } catch(const std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  } catch(const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}
