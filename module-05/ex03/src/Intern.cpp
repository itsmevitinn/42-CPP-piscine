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

Form* Intern::makeForm(std::string name, std::string target) {
  Form* sheets[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
  std::string forms[3] = {"Shrubbery", "Robotomy", "Presidential"};
  for (int i = 0; i < 3; i++) {
    if (name == forms[i]) {
      std::cout << "Intern creates " << forms[i] << std::endl;
      return (sheets[i]);
    }
  }
  throw Intern::InvalidForm();
  return (NULL);
}
