#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
 private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

 public:
  void complain(std::string level);
	//creating a type that will pointer to a member-function
	typedef void (Harl::*HarlMemFn)(void);
};

#endif
