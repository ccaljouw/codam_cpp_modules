/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/02 16:09:39 by cariencaljo   #+#    #+#                 */
/*   Updated: 2024/08/04 15:37:12 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void leaks(void) {
	std::cout << "*********************************" << std::endl;
	system("leaks form28 -q");
	std::cout << "*********************************" << std::endl;
}

void  testPresidentialPardonForm() {
  std::cout << "PRESIDENTIAL PARDON FORM" << std::endl;
  std::cout << "---------------------------------" << std::endl;
  std::cout << "Here come the bureacrats\n" << std::endl;
  Bureaucrat president("President", 1);
  std::cout << president << std::endl;

  Bureaucrat middleclassOfficial("Middleclass Official", 25);
  std::cout << middleclassOfficial << std::endl;
  
  Bureaucrat nobdody("Paper Pusher", 150);
  std::cout << nobdody << std::endl;
  std::cout << "---------------------------------" << std::endl;
  std::cout << "And the form...\n" << std::endl;

  AForm *PPF = new PresidentialPardonForm("Thief");
  std::cout << *PPF << std::endl;

  std::cout << "---------------------------------" << std::endl;
  try {
    std::cout << "Paper Pusher trying to execute presidential pardon..." << std::endl;
    PPF->beExecuted(nobdody);
  } catch(const std::exception& e) { 
    std::cerr << "Error executing form: " << e.what() << '\n';
  }

  try {
    std::cout << "\nMiddle class official giving it a try.." << std::endl;
    PPF->beExecuted(middleclassOfficial);
  } catch(const std::exception& e) { 
    std::cerr << "Error executing form: " << e.what() << '\n';
  }
  
  try {
    std::cout << "\nThe president.." << std::endl;
    PPF->beExecuted(president);
  } catch (std::exception &e) {
    std::cerr << "Error executing form: " << e.what() << '\n';
  }

  delete PPF;
}

void testRobotomyRequestForm() {
  std::cout << "\n---------------------------------" << std::endl;
  std::cout << "ROBOTOMY REQUEST FORM\n" << std::endl;
  std::cout << "---------------------------------" << std::endl;
  std::cout << "Here come the bureacrats\n" << std::endl;
  Bureaucrat useless("Useless", 150);
  std::cout << useless << std::endl;
  Bureaucrat canSingn("Signer", 72);
  std::cout << canSingn << std::endl;
  Bureaucrat canExecute("Executor", 45);
  std::cout << canExecute << std::endl;
  std::cout << "---------------------------------" << std::endl;
  std::cout << "And the form...\n" << std::endl;
  AForm *RRF = new RobotomyRequestForm("NoBot");
  std::cout << *RRF << std::endl;
  std::cout << "---------------------------------" << std::endl;
  try {
    std::cout << "Useless trying to execute..." << std::endl;
    RRF->beExecuted(useless);
  } catch(const std::exception& e) { 
    std::cerr << "Error executing form: " << e.what() << '\n';
  }

  try {
    std::cout << "\nSigner giving it a try.." << std::endl;
    RRF->beExecuted(canSingn);
  } catch(const std::exception& e) { 
    std::cerr << "Error executing form: " << e.what() << '\n';
  }
  
  try {
    std::cout << "\nAnd the executor.." << std::endl;
    RRF->beExecuted(canExecute);
  } catch (std::exception &e) {
    std::cerr << "Error executing form: " << e.what() << '\n';
  }
  delete RRF;
}

void testShrubberyCreationForm(std::string target) {
  std::cout << "\n---------------------------------" << std::endl;
  std::cout << "SHRUBBERY CREATION FORM\n" << std::endl;
  std::cout << "---------------------------------" << std::endl;
  std::cout << "Here come the bureacrats\n" << std::endl;
  Bureaucrat useless("Nobody", 150);
  std::cout << useless << std::endl;
  Bureaucrat canSingn("Garden planner", 145);
  std::cout << canSingn << std::endl;
  Bureaucrat canExecute("Gardener", 100);
  std::cout << canExecute << std::endl;
  std::cout << "And the form...\n" << std::endl;
  AForm *SCF = new ShrubberyCreationForm(target);
  std::cout << *SCF << std::endl;
  std::cout << "---------------------------------" << std::endl;
   try {
    std::cout << "Nobody trying to execute..." << std::endl;
    SCF->beExecuted(useless);
  } catch(const std::exception& e) { 
    std::cerr << "Error executing form: " << e.what() << '\n';
  }

  try {
    std::cout << "\nGarden planner giving it a try.." << std::endl;
    SCF->beExecuted(canSingn);
  } catch(const std::exception& e) { 
    std::cerr << "Error executing form: " << e.what() << '\n';
  }
  
  try {
    std::cout << "\nAnd the Gardener.." << std::endl;
    SCF->beExecuted(canExecute);
  } catch (std::exception &e) {
    std::cerr << "Error executing form: " << e.what() << '\n';
  }
  delete SCF;
}

int main(int argc, char **argv) {
  atexit(leaks);
  
  // testPresidentialPardonForm();
  // testRobotomyRequestForm();
  if (argc == 2)
    testShrubberyCreationForm(argv[1]);
  else
    testShrubberyCreationForm("default");
}
