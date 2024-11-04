#include "AForm.hpp"

class Intern {
  public:
    Intern();
    ~Intern();

    AForm *makeForm(std::string formName, std::string target);

  private:
    class FormNotFoundException;
    
    Intern(const Intern& rhs);
    Intern &operator=(const Intern& other);
};

class Intern::FormNotFoundException : public std::exception {
  public:
    FormNotFoundException(const std::string& form);
    ~FormNotFoundException() throw();

    virtual const char *what() const throw();

  private:
    std::string _form;
    std::string _message;
};
