#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
  return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
  if (grade < 1) {
    throw GradeTooHighException();
  }
  if (grade > 150) {
    throw GradeTooLowException();
  }
  this->_grade = grade;
  return;
}

Bureaucrat::Bureaucrat(Bureaucrat const& rhs) : _name(rhs.getName()), _grade(rhs.getGrade()) {
  return;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
  if (this != &rhs) {
    this->_grade = rhs.getGrade();
  }
  std::cout << "Cannot change the name of a bureaucrat" << std::endl;
  return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
  return this->_name;
}

int Bureaucrat::getGrade() const {
  return this->_grade;
}

void Bureaucrat::addGrade() {
  if (this->_grade == 1) {
    throw GradeTooHighException();
  }
  this->_grade--;
}

void Bureaucrat::subGrade() {
  if(this->_grade == 150) {
    throw GradeTooLowException();
  }
  this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
  return "Grade Too High!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
  return "Grade Too Low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return (out);
}
