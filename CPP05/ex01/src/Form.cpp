#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(1), _execGrade(1) {
    return;
}

Form::Form(std::string name, int signGrade, int execGrade) \
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

Form::Form(Form const& rhs) \
  : _name(rhs.getName()), _signed(rhs.getSigned()), _signGrade(rhs.getSignGrade()), \
  _execGrade(rhs.getExecGrade()) {
    return;
}

Form::~Form() {}

std::string Form::getName() const {
    return this->_name;
}

int Form::getSignGrade() const {
    return this->_signGrade;
}

int Form::getExecGrade() const {
    return this->_execGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_signGrade) {
      throw GradeTooLowException();
    }
    this->_signed = true;
}

bool Form::getSigned() const {
    return this->_signed;
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form grade Too Low!";
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Form grade Too High!";
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << form.getName() << "\n- ";
    if (form.getSigned()) {
        out << "Signed";
    } else {
        out << "Not signed\n- ";
    }
    out << form.getSignGrade() << " required to sign\n- " \
      << form.getExecGrade() << " required to execute." << std::endl;
    return out;
}

Form& Form::operator=(Form const& rhs) {
    if (this != &rhs) {
        this->_signed = rhs.getSigned();
    }
     std::cout << "Cannot copy values into const attributes" << std::endl;
    return *this;
}

