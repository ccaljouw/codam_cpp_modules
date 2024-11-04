#include "../include/AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(1), _execGrade(1) {
    return;
}

AForm::AForm(std::string name, int signGrade, int execGrade) \
: _name(name), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1) {
      throw GradeTooHighException();
    }
    if (signGrade > 150 || execGrade > 150) {
        throw GradeTooLowException();
    }
    this->_signed = false;
    return;
}

AForm::AForm(AForm const& rhs) \
  : _name(rhs.getName()), _signed(rhs.getSigned()), _signGrade(rhs.getSignGrade()), \
  _execGrade(rhs.getExecGrade()) {
    return;
}

AForm::~AForm() {}

std::string AForm::getName() const {
    return this->_name;
}

int AForm::getSignGrade() const {
    return this->_signGrade;
}

int AForm::getExecGrade() const {
    return this->_execGrade;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_signGrade) {
      throw GradeTooLowException();
    }
    this->_signed = true;
}

bool AForm::getSigned() const {
    return this->_signed;
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Form grade Too Low!";
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Form grade Too High!";
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm) {
    out << AForm.getName() << "\n- ";
    if (AForm.getSigned()) {
        out << "Signed";
    } else {
        out << "Not signed\n- ";
    }
    out << AForm.getSignGrade() << " required to sign\n- " \
      << AForm.getExecGrade() << " required to execute." << std::endl;
    return out;
}

AForm& AForm::operator=(AForm const& rhs) {
    if (this != &rhs) {
        this->_signed = rhs.getSigned();
    }
     std::cout << "Cannot copy values into const attributes" << std::endl;
    return *this;
}

void AForm::beExecuted(Bureaucrat &bureaucrat) {
    try {
      if (!this->_signed) {
        std::cout << "Form not signed yet, I will try to sign it myself" << std::endl;
        bureaucrat.signForm(*this);
      }
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
    if (bureaucrat.getGrade() > this->_execGrade) {
      throw GradeTooLowException();
    }
    this->execute(bureaucrat);
}



