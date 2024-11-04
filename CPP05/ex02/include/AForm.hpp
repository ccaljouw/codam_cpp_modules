#ifndef AForm_H
# define AForm_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat; 

class AForm {
  public:
    AForm();
    AForm(std::string name, int signGrade, int execGrade);
    AForm(AForm const& rhs);
    virtual ~AForm();

    std::string getName() const;
    int   getSignGrade() const;
    int   getExecGrade() const;
    bool  getSigned() const;

    void  beSigned(Bureaucrat& bureaucrat);
    void  beExecuted(Bureaucrat& bureaucrat);

    virtual void execute(Bureaucrat const& executor) const = 0;

  private:
    class GradeTooLowException;
    class GradeTooHighException;
    
    const     std::string _name;
    bool      _signed;
    const int _signGrade;
    const int _execGrade;

    AForm& operator=(AForm const& rhs);
};

class AForm::GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
};

class AForm::GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif
