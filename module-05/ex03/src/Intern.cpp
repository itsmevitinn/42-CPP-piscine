#include "../includes/Intern.hpp"

#include "../includes/Form.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

Intern::Intern(void) {
}

Intern::~Intern(void) {
}

Intern::Intern(const Intern& instance) {
  (void)instance;
}

Intern& Intern::operator=(const Intern& instance) {
  (void)instance;
  return (*this);
}

const char* Intern::InvalidForm::what() const throw() {
  return ("Invalid form name!");
}

Form* Intern::makeShrub(std::string target) {
  return (new ShrubberyCreationForm(target));
}
Form* Intern::makeRobo(std::string target) {
  return (new RobotomyRequestForm(target));
}
Form* Intern::makePres(std::string target) {
  return (new PresidentialPardonForm(target));
}

Form* Intern::makeForm(std::string name, std::string target) {
  Form* selected;
  InternForm types[3] = {&Intern::makeShrub, &Intern::makeRobo, &Intern::makePres};
  std::string forms[3] = {"Shrubbery", "Robotomy", "Presidential"};
  for (int i = 0; i < 3; i++) {
    if (name == forms[i]) {
      selected = (this->*types[i])(target);
      std::cout << "Intern creates " << forms[i] << std::endl;
      return (selected);
    }
  }
  throw Intern::InvalidForm();
  return (NULL);
}
