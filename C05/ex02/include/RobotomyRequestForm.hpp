#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
  public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const& rhs);
    virtual ~RobotomyRequestForm();

    void execute(Bureaucrat const& executor) const;

  private: 
    std::string _target;
    
    RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);
};
