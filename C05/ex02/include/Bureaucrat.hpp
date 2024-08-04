#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

  public:
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    
    void addGrade(void);
    void subGrade(void);
    void signForm(AForm& form);


  private:
    class GradeTooLowException;
    class GradeTooHighException;

    const std::string _name;
    int _grade;

    Bureaucrat();
    Bureaucrat(const Bureaucrat &obj);
    Bureaucrat& operator=(const Bureaucrat &obj);
};

class Bureaucrat::GradeTooLowException : public std::exception {
  public:
    virtual const char* what() const throw();
};

class Bureaucrat::GradeTooHighException: public std::exception {
  public:
    virtual const char* what() const throw();
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj);

#endif
