#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat; 

class Form {
  public:
    Form();
    Form(std::string name, int signGrade, int execGrade);
    Form(Form const& rhs);
    ~Form();

    std::string getName() const;
    int         getSignGrade() const;
    int         getExecGrade() const;
    bool        getSigned() const;

    void beSigned(Bureaucrat& bureaucrat);

  private:
    class GradeTooLowException;
    class GradeTooHighException;

    const     std::string _name;
    bool      _signed;
    const int _signGrade;
    const int _execGrade;

    Form& operator=(Form const& rhs);
};

class Form::GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
};

class Form::GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
