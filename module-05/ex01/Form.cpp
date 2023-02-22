#include "Form.hpp"

// constructors and destructors
Form::Form(void) : _name("undefined"), _signed(false), _signGrade(0), _execGrade(0) {
  std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, const int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
  if (this->getSignGrade() > 150 || this->getExecGrade() > 150) {
    Form::GradeTooHighException("signGrade or execGrade is too high!");
  } else if (this->getSignGrade() < 1 || this->getExecGrade() < 1) {
    Form::GradeTooLowException("signGrade or execGrade is too low!");
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

// my custom exceptions
Form::GradeTooHighException::GradeTooHighException(std::string message) {
  this->message = message;
}

Form::GradeTooLowException::GradeTooLowException(std::string message) {
  this->message = message;
}

const char* Form::GradeTooHighException::what() const throw() {
  return (this->message.c_str());
}

const char* Form::GradeTooLowException::what() const throw() {
  return (this->message.c_str());
}

// member function
void Form::beSigned(Bureaucrat& politician) {
  if (politician.getGrade() <= this->getSignGrade()) {
    this->_signed = true;
  } else {
    Form::GradeTooLowException("Bureaucrat grade is too low and form wasn't signed!");
  }
}

// global overload
std::ostream& operator<<(std::ostream& os, const Form& sheet) {
  os << "Form name: " << sheet.getName() << std::endl;
  os << "Form signed: " << sheet.getSigned() << std::endl;
  os << "Form sign grade: " << sheet.getSignGrade() << std::endl;
  os << "Form exec grade: " << sheet.getExecGrade() << std::endl;
  return (os);
}
