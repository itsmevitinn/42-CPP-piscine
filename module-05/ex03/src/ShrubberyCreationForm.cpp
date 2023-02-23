#include "ShrubberyCreationForm.hpp"
ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("unnamed", "non targeted", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shruberry", target, 145, 137) {
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& instance) : Form(instance) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& instance) {
  Form::operator=(instance);
  return (*this);
}

void ShrubberyCreationForm::action(Bureaucrat const& executor) const {
  Form::execute(executor);
  std::ofstream file;
  file.open((this->getTarget() + "_shrubbery").c_str());
  if (!file.is_open()) {
    throw std::ofstream::failure("Failed to open file!");
  }
  file << "              v .   ._, |_  .," << std::endl;
  file << "           `-._\\/  .  \\ /    |/_" << std::endl;
  file << "               \\  _\\, y | \\//" << std::endl;
  file << "         _\\_.___\\, \\/ -.\\||" << std::endl;
  file << "           `7-,--.`._||  / / ," << std::endl;
  file << "           /'     `-. `./ / |/_.'" << std::endl;
  file << "                     |    |//" << std::endl;
  file << "                     |_    /" << std::endl;
  file << "                     |-   |" << std::endl;
  file << "                     |   =|" << std::endl;
  file << "                     |    |" << std::endl;
  file << "--------------------/ ,  . \\--------" << std::endl;
}
