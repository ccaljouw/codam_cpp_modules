#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() \
  : AForm("PresidentialPardonForm", 25, 5), _target("defaultPPF") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) \
  : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& rhs) \
  : AForm(rhs) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs) {
  (void)rhs;  
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()  {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  (void)executor;
  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

