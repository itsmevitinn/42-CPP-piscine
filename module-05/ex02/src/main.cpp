#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
int main(void) {
  try {
    Bureaucrat obama("obama", 5);
    Bureaucrat joebiden("joebiden", 150);

    ShrubberyCreationForm shrubbery("fruit");
    std::cout << shrubbery << std::endl;
    obama.executeForm(shrubbery);
    joebiden.executeForm(shrubbery);
    joebiden.signForm(shrubbery);
    obama.signForm(shrubbery);
    joebiden.signForm(shrubbery);
    obama.executeForm(shrubbery);

    RobotomyRequestForm robotomy("pedreiro");
    std::cout << robotomy << std::endl;
    obama.executeForm(robotomy);
    joebiden.executeForm(robotomy);
    joebiden.signForm(robotomy);
    obama.signForm(robotomy);
    joebiden.signForm(robotomy);
    obama.executeForm(robotomy);

    PresidentialPardonForm presidential("george bush");
    std::cout << presidential << std::endl;
    obama.executeForm(presidential);
    joebiden.executeForm(presidential);
    joebiden.signForm(presidential);
    obama.signForm(presidential);
    joebiden.signForm(presidential);
    obama.executeForm(presidential);

    ShrubberyCreationForm teste("rato");
    ShrubberyCreationForm teste2(teste);
    std::cout << teste2.getTarget() << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
