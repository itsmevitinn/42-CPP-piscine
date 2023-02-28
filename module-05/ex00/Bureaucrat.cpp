#include "Bureaucrat.hpp"

// constructors and destructors
Bureaucrat::Bureaucrat(void) : _name("non-defined"), _grade(150) {
  std::cout << "Bureaucrat default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
  std::cout << "Bureaucrat name & grade constructor called" << std::endl;
  if (grade > 150) {
    // throwing the custom exception
    throw Bureaucrat::GradeTooLowException();
  } else if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else {
    this->_grade = grade;
  }
}
Bureaucrat::~Bureaucrat(void) {
  std::cout << "Bureaucrat " << this->getName() << " destructor called" << std::endl;
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& instance) {
  std::cout << "Bureaucrat copy constructor called" << std::endl;
  if (this != &instance) {
    *this = instance;
  } else {
    std::cout << "Cannot assign duplicated instances!" << std::endl;
  }
}

// copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& instance) {
  this->_grade = instance._grade;
  return (*this);
}

// member functions
std::string Bureaucrat::getName(void) const {
  return (this->_name);
}
int Bureaucrat::getGrade(void) const {
  return (this->_grade);
}
void Bureaucrat::reduceGrade(void) {
  if (++this->_grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
}
void Bureaucrat::increaseGrade(void) {
  if (--this->_grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  }
}

// custom exceptions (overriding the virtual member-function std::exception::what from std::exception)
const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade is too high!");
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade is too low!");
}

// global overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& politician) {
  os << politician.getName() << ", bureaucrat grade " << politician.getGrade() << ".";
  return os;
}
