#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat {

  public:
      Bureaucrat(std::string name, int grade);
      ~Bureaucrat();

      std::string getName() const;
      int getGrade() const;
      
      void addGrade(void);
      void subGrade(void);
      void signForm(Form& form);

      class GradeTooLowException;
      class GradeTooHighException;

  private:
    
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
