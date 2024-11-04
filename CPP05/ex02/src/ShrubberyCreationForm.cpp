#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() \
  : AForm("ShrubberyCreationForm", 145, 137), _target("defaultSCF") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) \
  : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& rhs) \
  : AForm(rhs) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs) {
  (void)rhs;  
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()  {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  (void)executor;
  std::ofstream outFile(this->_target + "_shrubbery" + ".txt");
  if(!outFile.is_open()) {
    std::cerr << "Error: could not open file " << this->_target << std::endl;
    throw std::exception();
  }

  std::string tree =
        "           *\n"
        "          / \\\n"
        "         /   \\\n"
        "        /     \\\n"
        "       /       \\\n"
        "       ---------\n"
        "        /     \\\n"
        "       /       \\\n"
        "      /         \\\n"
        "      -----------\n"
        "          | |\n"
        "          | |\n"
        "          ---\n";
  
  outFile << tree << tree << tree;
  outFile.close();

  std::cout << "Shrubbery has been created in " << this->_target << "_shrubbery" << std::endl;
}
