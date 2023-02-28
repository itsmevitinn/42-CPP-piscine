#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
 public:
  // constructors and destructors
  ShrubberyCreationForm(std::string target);
  ~ShrubberyCreationForm(void);
  // copy constructors
  ShrubberyCreationForm(const ShrubberyCreationForm& instance);
  // copy assignment operator overload
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& instance);
  void action(Bureaucrat const& executor) const;
};

#endif
