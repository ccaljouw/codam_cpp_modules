#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& rhs) {
  if (this != &rhs)
    *this = rhs;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& rhs) {
  (void)rhs;
  return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target) {
  std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
  typedef AForm *(*creatorFuncPtr)(std::string targetForm);
  creatorFuncPtr formCreators[3] = {
      [](std::string targetForm) -> AForm* {return new PresidentialPardonForm(targetForm);},
      [](std::string targetForm) -> AForm* {return new RobotomyRequestForm(targetForm);},
      [](std::string targetForm) -> AForm* {return new ShrubberyCreationForm(targetForm);}
  };
  for (int i = 0; i < 3; i++) {
    if (formName == formNames[i]) {
      std::cout << "Intern creates " << formName << " form" << std::endl;
      return formCreators[i](target);
    }
  }
  throw FormNotFoundException(formName);
}

const char *Intern::FormNotFoundException::what() const throw() {
  return _message.c_str();
}

Intern::FormNotFoundException::FormNotFoundException(const std::string& form) : _form(form), _message("Intern could not find form " + _form + "!") {}

Intern::FormNotFoundException::~FormNotFoundException() throw() {}
