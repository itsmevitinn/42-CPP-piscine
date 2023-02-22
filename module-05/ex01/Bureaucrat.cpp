#include "Bureaucrat.hpp"

// constructors and destructors
Bureaucrat::Bureaucrat(void) : _name("non-defined"), _grade(150) {
  std::cout << "Bureaucrat default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
  std::cout << "Bureaucrat name & grade constructor called" << std::endl;
  if (grade > 150) {
    // throwing the custom exception
    throw Bureaucrat::GradeTooHighException("Bureaucrat grade is too high!");
  } else if (grade < 1) {
    throw Bureaucrat::GradeTooLowException("Bureaucrat grade is too low!");
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
  std::cout << "Bureaucrat copy assignment overload called" << std::endl;
  return (*this);
}

// member functions
std::string Bureaucrat::getName(void) const {
  return (this->_name);
}
int Bureaucrat::getGrade(void) const {
  return (this->_grade);
}
void Bureaucrat::increaseGrade(void) {
  if (++this->_grade > 150) {
    throw Bureaucrat::GradeTooHighException("Bureaucrat grade is too high after increase!");
  }
}
void Bureaucrat::reduceGrade(void) {
  if (--this->_grade < 1) {
    throw Bureaucrat::GradeTooLowException("Bureaucrat grade is too low after increase!");
  }
}

void Bureaucrat::signForm(Form& sheet) {
  try {
    sheet.beSigned(*this);
    if (sheet.getSigned() == true) {
      std::cout << this->getName() << " signed " << sheet.getName() << std::endl;
    } else {
      throw Bureaucrat::FormNotSigned(this->getName() + " couldn't sign " + sheet.getName() + " because his grade is too low!");
    }
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}

// custom exceptions (overriding the virtual member-function std::exception::what from std::exception)

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string message) {
  this->message = message;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string message) {
  this->message = message;
}

Bureaucrat::FormNotSigned::FormNotSigned(std::string message) {
  this->message = message;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return (this->message.c_str());
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return (this->message.c_str());
}

const char* Bureaucrat::FormNotSigned::what() const throw() {
  return (this->message.c_str());
}

// global overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& politician) {
  os << politician.getName() << ", bureaucrat grade " << politician.getGrade() << ".";
  return os;
}
