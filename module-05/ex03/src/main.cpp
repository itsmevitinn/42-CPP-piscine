#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
int main(void) {
  try {
    Intern someRandomIntern;
    std::string types[3] = {"Shrubbery", "Robotomy", "Presidential"};
    Form* forms[3];
    for (int i = 0; i < 3; i++) {
      forms[i] = someRandomIntern.makeForm(types[i], "Internship");
    }

    Bureaucrat obama("obama", 5);
    Bureaucrat joebiden("joebiden", 150);
    for (int i = 0; i < 3; i++) {
      std::cout << *forms[i] << std::endl;
      obama.executeForm(*forms[i]);
      joebiden.executeForm(*forms[i]);
      joebiden.signForm(*forms[i]);
      obama.signForm(*forms[i]);
      joebiden.signForm(*forms[i]);
      obama.executeForm(*forms[i]);
    }
    for (int i = 0; i < 3; i++) {
      delete forms[i];
    }
    Form* invalidname = someRandomIntern.makeForm("", "Salve");
    std::cout << *invalidname;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
