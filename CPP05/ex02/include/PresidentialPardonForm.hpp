#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
  public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const& rhs);
    virtual ~PresidentialPardonForm();

    void execute(Bureaucrat const& executor) const;

  private:
    std::string _target;
    
    PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);
};
