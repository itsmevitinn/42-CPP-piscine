#include "Bureaucrat.hpp"

int main(void) {
  try {
    Bureaucrat rat;
    Bureaucrat politician1("obama", 3);
    Bureaucrat politician2("joebiden", 148);
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
    Bureaucrat politician1("obama", 0);
    Bureaucrat politician2("joebiden", 100);
    std::cout << politician2 << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
