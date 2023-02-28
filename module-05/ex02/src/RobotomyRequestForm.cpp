#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy", target, 72, 45) {
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& instance) : Form(instance) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& instance) {
  Form::operator=(instance);
  return (*this);
}

void RobotomyRequestForm::action(Bureaucrat const& executor) const {
  Form::execute(executor);
  std::cout << "Making some drilling noises!" << std::endl;
  if ((rand() % 10) <= 4) {
    std::cout << this->getTarget() << " has been robotomized!" << std::endl;
  } else {
    std::cout << "robotomization on " << this->getTarget() << " has failed!" << std::endl;
  }
}
