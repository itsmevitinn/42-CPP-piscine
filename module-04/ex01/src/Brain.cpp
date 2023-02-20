#include "Brain.hpp"

// constructor
Brain::Brain(void) {
  std::string ideas[] = {
    "Wondering when i will become a human coder",
    "Im hungry",
    "Im thirsty",
    "Hello guys!",
    "Whats up"
  };
  for (int i = 0; i < 100; i++) {
    this->_ideas[i] = ideas[i % 5];
  }
  std::cout << "Brain default constructor called" << std::endl;
}

// copy constructor
Brain::Brain(const Brain& instance) {
  std::cout << "Brain copy constructor called" << std::endl;
  if (this != &instance) {
    *this = instance;
  } else {
    std::cout << "Cannot assign duplicated instances!" << std::endl;
  }
}

// copy assignment operator
Brain& Brain::operator=(const Brain& copy) {
  std::cout << "Brain copy assignment overload called" << std::endl;
  for (int i = 0; i < 100; i++) {
    this->_ideas[i] = copy._ideas[i];
  }
  return (*this);
}

// destructor
Brain::~Brain(void) {
  std::cout << "Brain destructor called" << std::endl;
}

// member function

std::string Brain::getIdea(int index) const {
  return (this->_ideas[index]);
}
