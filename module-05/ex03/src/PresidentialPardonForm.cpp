#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("unnamed", "non targeted", 72, 45) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential", target, 25, 5) {
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& instance) : Form(instance) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& instance) {
  Form::operator=(instance);
  return (*this);
}

void PresidentialPardonForm::action(Bureaucrat const& executor) const {
  Form::execute(executor);
  std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
