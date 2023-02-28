#include "../includes/Form.hpp"

#include "Bureaucrat.hpp"

// constructors and destructors
Form::Form(void) : _name("undefined"), _signed(false), _signGrade(0), _execGrade(0) {
}

Form::Form(std::string name, const int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
  if (this->getSignGrade() > 150 || this->getExecGrade() > 150) {
    throw Form::GradeTooLowException();
  } else if (this->getSignGrade() < 1 || this->getExecGrade() < 1) {
    throw Form::GradeTooHighException();
  }
}

Form::Form(std::string name, std::string target, const int signGrade, int execGrade) : _name(name), _target(target), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
  if (this->getSignGrade() > 150 || this->getExecGrade() > 150) {
    throw Form::GradeTooLowException();
  } else if (this->getSignGrade() < 1 || this->getExecGrade() < 1) {
    throw Form::GradeTooHighException();
  }
}

Form::~Form(void) {
}

// copy constructor
Form::Form(const Form& instance) : _name(instance._name), _target(instance._target), _signed(instance._signed), _signGrade(instance._signGrade), _execGrade(instance._execGrade) {
}

// copy assignment operator
Form& Form::operator=(const Form& instance) {
  this->_signed = instance._signed;
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

std::string Form::getTarget(void) const {
  return (this->_target);
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

void Form::execute(Bureaucrat const& executor) const {
  if (executor.getGrade() > this->getExecGrade()) {
    throw Form::GradeTooLowException();
  }
  if (!this->getSigned()) {
    throw Form::NotSigned();
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
  return ("Form is already signed!");
}

const char* Form::NotSigned::what() const throw() {
  return ("form is not signed!");
}

// global overload
std::ostream& operator<<(std::ostream& os, const Form& sheet) {
  os << std::endl
     << "Form name: " << sheet.getName() << std::endl;
  os << "signed: " << std::boolalpha << sheet.getSigned();
  os << " | sign grade: " << sheet.getSignGrade();
  os << " | exec grade: " << sheet.getExecGrade() << std::endl;
  return (os);
}
