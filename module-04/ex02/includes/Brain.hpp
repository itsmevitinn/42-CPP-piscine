#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
 private:
  std::string _ideas[100];

 public:
  // constructors
  Brain(void);
  // copy constructors
  Brain(const Brain& copy);
  // destructors
  ~Brain(void);
  // copy assignment operator overload
  Brain& operator=(const Brain& copy);
  // member function
  std::string getIdea(int index) const;
};

#endif
