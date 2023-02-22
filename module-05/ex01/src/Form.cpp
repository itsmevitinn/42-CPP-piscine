#include "Form.hpp"

#include "Bureaucrat.hpp"

// constructors and destructors
Form::Form(void) : _name("undefined"), _signed(false), _signGrade(0), _execGrade(0) {
  std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, const int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
  if (this->getSignGrade() > 150 || this->getExecGrade() > 150) {
    throw Form::GradeTooHighException();
  } else if (this->getSignGrade() < 1 || this->getExecGrade() < 1) {
    throw Form::GradeTooLowException();
  }
  std::cout << "Form fill constructor called" << std::endl;
}

Form::~Form(void) {
  std::cout << "Form destructor called" << std::endl;
}

// copy constructor
Form::Form(const Form& instance) : _name(instance._name), _signed(instance._signed), _signGrade(instance._signGrade), _execGrade(instance._execGrade) {
  std::cout << "Form copy constructor called" << std::endl;
}

// copy assignment operator
Form& Form::operator=(const Form& instance) {
  this->_signed = instance._signed;
  std::cout << "Form copy assignment overload called" << std::endl;
  return (*this);
}

// getters
std::string Form::getName(void) const {
  return (this->_name);
}

bool Form::getSigned(void) const {
  return (this->_signed);
}

int Form::getSignGrade(void) const {
  return (this->_signGrade);
}

int Form::getExecGrade(void) const {
  return (this->_execGrade);
}

// member function
void Form::beSigned(Bureaucrat& politician) {
  if (!this->getSigned()) {
    if (politician.getGrade() <= this->getSignGrade()) {
      this->_signed = true;
    } else {
      throw Form::GradeTooLowException();
    }
  } else {
    throw Form::AlreadySigned();
  }
}

// my custom exceptions
const char* Form::GradeTooHighException::what() const throw() {
  return ("grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
  return ("his grade is too low!");
}

const char* Form::AlreadySigned::what() const throw() {
  return ("form is already signed!");
}

// global overload
std::ostream& operator<<(std::ostream& os, const Form& sheet) {
  os << std::endl << "Form name: " << sheet.getName() << std::endl;
  os << "signed: " << std::boolalpha << sheet.getSigned();
  os << " | sign grade: " << sheet.getSignGrade();
  os << " | exec grade: " << sheet.getExecGrade() << std::endl;
  return (os);
}
