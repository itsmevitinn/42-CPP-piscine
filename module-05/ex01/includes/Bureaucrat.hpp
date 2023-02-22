#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat {
 private:
  const std::string _name;
  int _grade;

 public:
  // constructors and destructors
  Bureaucrat(void);
  Bureaucrat(std::string name, int grade);
  ~Bureaucrat(void);

  // copy constructors
  Bureaucrat(const Bureaucrat& instance);

  // copy assignment operator overload
  Bureaucrat& operator=(const Bureaucrat& instance);

  // member functions
  std::string getName(void) const;
  int getGrade(void) const;
  void increaseGrade(void);
  void reduceGrade(void);
  void signForm(Form& sheet);

  // my custom exceptions
  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };
  class FormNotSigned : public std::exception {
   public:
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& politician);

#endif
