#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const& rhs);
    virtual ~ShrubberyCreationForm();

    void execute(Bureaucrat const& executor) const;

  private:
    std::string _target;
    
    ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);
};


