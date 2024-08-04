#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() \
  : AForm("RobotomyRequestForm", 72, 45), _target("defaultRRF") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) \
  : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& rhs) \
  : AForm(rhs) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs) {
  (void)rhs;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  (void)executor;
  std::cout << "Brrrrrrr" << std::endl;
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  int randomValue = std::rand() % 2;
  if (randomValue == 0) {
    std::cout << this->_target << " has not been robotomized." << std::endl;
  } else {
    std::cout << this->_target << " has been robotomized successfully." << std::endl;
  }
}

