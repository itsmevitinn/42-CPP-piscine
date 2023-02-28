#include "../includes/Bureaucrat.hpp"

#include "../includes/Form.hpp"

// constructors and destructors
Bureaucrat::Bureaucrat(void) : _name("non-defined"), _grade(150) {
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
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
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& instance) {
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

void Bureaucrat::signForm(Form& sheet) {
  try {
    sheet.beSigned(*this);
    if (sheet.getSigned() == true) {
      std::cout << this->getName() << " signed " << sheet.getName() << std::endl;
    }
  } catch (std::exception& e) {
    std::cout << this->getName() << " couldn't sign " << sheet.getName() << " because " << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(Form const& form) {
  try {
    form.action(*this);
    std::cout << this->getName() << " executed " << form.getName() << std::endl;
  } catch (std::exception& e) {
    std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
  }
}

// custom exceptions (overriding the virtual member-function std::exception::what from std::exception)
const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Bureaucrat: Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Bureaucrat: Grade is too low!");
}

const char* Bureaucrat::FormNotSigned::what() const throw() {
  return ("Bureaucrat: Form wasn't signed because !");
}

// global overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& politician) {
  os << politician.getName() << ", bureaucrat grade " << politician.getGrade() << ".";
  return os;
}
