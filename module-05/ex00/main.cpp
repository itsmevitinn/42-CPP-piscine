#include "Bureaucrat.hpp"

int main(void) {
  try {
    Bureaucrat rat;
    Bureaucrat politician1("obama", 148);
    Bureaucrat politician2("joebiden", 3);
    std::cout << rat << std::endl;

    politician1.reduceGrade();
    std::cout << politician1 << std::endl;
    politician1.reduceGrade();
    std::cout << politician1 << std::endl;

    politician2.increaseGrade();
    std::cout << politician2 << std::endl;
    politician2.increaseGrade();
    std::cout << politician2 << std::endl;
    politician2.increaseGrade();

  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Bureaucrat politician1("obama", 151);
    std::cout << politician1 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
