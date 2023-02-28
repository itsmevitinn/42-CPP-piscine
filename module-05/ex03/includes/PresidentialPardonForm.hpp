#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
 public:
  // constructors and destructors
  PresidentialPardonForm(std::string target);
  ~PresidentialPardonForm(void);
  // copy constructors
  PresidentialPardonForm(const PresidentialPardonForm& instance);
  // copy assignment operator overload
  PresidentialPardonForm& operator=(const PresidentialPardonForm& instance);
  void action(Bureaucrat const& executor) const;
};

#endif
