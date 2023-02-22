#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 private:
  const std::string _name;
  bool _signed;
  const int _signGrade;
  const int _execGrade;

 public:
  // constructors and destructors
  Form(void);
  Form(std::string name, int signGrade, int execGrade);
  ~Form(void);

  // copy constructors
  Form(const Form& copy);

  // copy assignment operator overload
  Form& operator=(const Form& instance);

  // getters
  std::string getName(void) const;
  bool getSigned(void) const;
  int getSignGrade(void) const;
  int getExecGrade(void) const;

  // member functions
  void beSigned(Bureaucrat& politician);

  // my custom exceptions
  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };
  class AlreadySigned : public std::exception {
   public:
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, const Form& sheet);

#endif
