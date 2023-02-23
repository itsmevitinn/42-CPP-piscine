#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern {
 public:
  // constructors and destructors
  Intern(void);
  ~Intern(void);
  // copy constructors
  Intern(const Intern& instance);
  // copy assignment operator overload
  Intern& operator=(const Intern& instance);
  Form* makeForm(std::string name, std::string target);
  class InvalidForm : public std::exception {
   public:
    const char* what() const throw();
  };
  typedef Form* (Intern::*InternForm)(std::string target);

 private:
  Form* makeShrub(std::string target);
  Form* makeRobo(std::string target);
  Form* makePres(std::string target);
};

#endif
