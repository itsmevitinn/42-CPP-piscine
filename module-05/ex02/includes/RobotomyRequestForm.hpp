#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form{
 public:
  // constructors and destructors
  RobotomyRequestForm(void);
  RobotomyRequestForm(std::string target);
  ~RobotomyRequestForm(void);
  // copy constructors
  RobotomyRequestForm(const RobotomyRequestForm& instance);
  // copy assignment operator overload
  RobotomyRequestForm& operator=(const RobotomyRequestForm& instance);
  void action(Bureaucrat const& executor) const;
};

#endif
