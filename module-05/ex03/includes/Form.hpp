#ifndef FORM_HPP
#define FORM_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
 private:
  const std::string _name;
  const std::string _target;
  bool _signed;
  const int _signGrade;
  const int _execGrade;

 public:
  // constructors and destructors
  Form(void);
  Form(std::string name, std::string target);
  Form(std::string name, int signGrade, int execGrade);
  Form(std::string name, std::string target, int signGrade, int execGrade);
  virtual ~Form(void);

  // copy constructors
  Form(const Form& copy);

  // copy assignment operator overload
  Form& operator=(const Form& instance);

  // getters
  std::string getName(void) const;
  bool getSigned(void) const;
  int getSignGrade(void) const;
  int getExecGrade(void) const;
  std::string getTarget(void) const;

  // member functions
  void beSigned(Bureaucrat& politician);
  void execute(Bureaucrat const& executor) const;
  virtual void action(Bureaucrat const& executor) const = 0;
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
  class NotSigned : public std::exception {
   public:
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, const Form& sheet);

#endif
