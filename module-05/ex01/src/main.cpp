#include "../includes/Form.hpp"
#include "Bureaucrat.hpp"
int main(void) {
  try {
    Bureaucrat politician2("joebiden", 149);
    politician2.increaseGrade();
    std::cout << politician2 << std::endl;
    politician2.increaseGrade();
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Bureaucrat politician1("obama", 2);
    politician1.reduceGrade();
    std::cout << politician1 << std::endl;
    politician1.reduceGrade();
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Bureaucrat politician5("jonata", 200);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Bureaucrat politician6("giga", 0);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Bureaucrat politician3("obama", 40);
    Bureaucrat politician4("joebiden", 40);
    Form sheet("gsheet", 50, 50);
    politician3.signForm(sheet);
    politician4.signForm(sheet);
    Form sheet2("testsheet", 20, 20);
    politician3.signForm(sheet2);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
