/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/02 16:09:39 by cariencaljo   #+#    #+#                 */
/*   Updated: 2024/08/02 21:31:13 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void leaks(void) {
	std::cout << "---------------------------------" << std::endl;
	system("leaks bureaucrat -q");
	std::cout << "---------------------------------" << std::endl;
}

int main() {
  atexit(leaks);
  try {
    Bureaucrat best("Best", 1);
    std::cout << best << std::endl;

    Bureaucrat worst("Worst", 150);
    std::cout << worst << std::endl;

    Bureaucrat middle("Middle", 75);
    std::cout << middle << std::endl;

    try {      
      std::cout << "Construction with low value" << std::endl;
      Bureaucrat tooGood("TooGood", 0);
    } catch(const std::exception& e){
      std::cout << e.what() << std::endl;
    }

    try {
      std::cout << "Construction with high value" << std::endl;
      Bureaucrat tooBad("TooBad", 151);
      std::cout << tooBad << std::endl;
    } catch(const std::exception& e){
      std::cout << e.what() << std::endl;
    }

    try{
      std::cout << middle << std::endl;
      middle.addGrade();
      std::cout << middle << std::endl;
      middle.subGrade();
      std::cout << middle << std::endl;
    } catch(const std::exception& e) {
      std::cout << e.what() << std::endl;
    }

    try {
      std::cout << "Adding to min value" << std::endl;
      best.addGrade();
    } catch(const std::exception& e) {
      std::cout << e.what() << std::endl;
    }

    try {
      std::cout << best << std::endl;
      best.subGrade();
      std::cout << best << std::endl;
    } catch(const std::exception& e) {
      std::cout << e.what() << std::endl;
    }

    try {
      std::cout << worst << std::endl;
      worst.addGrade();
      std::cout << worst << std::endl;
    } catch(const std::exception& e) {
      std::cerr << e.what() << std::endl;
    }

    try {
      worst.subGrade();
      std::cout << worst << std::endl;
      std::cout << "Subctracting from max vanlue" << std::endl;
      worst.subGrade();
    } catch(const std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
    
  } catch(const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}
