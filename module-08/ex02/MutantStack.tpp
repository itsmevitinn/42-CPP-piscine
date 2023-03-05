#include "MutantStack.hpp"

// constructors and destructors
template <typename T, typename List>
MutantStack<T, List>::MutantStack(void) : std::stack<T, List>() {
}

template <typename T, typename List>
MutantStack<T, List>::MutantStack(const MutantStack& instance) : std::stack<T, List>(instance) {
}

template <typename T, typename List>
MutantStack<T, List>::~MutantStack(void) {
}

// copy assignment operator overload
template <typename T, typename List>
MutantStack<T, List>& MutantStack<T, List>::operator=(const MutantStack<T, List>& instance) {
  if (this != &instance)
    std::stack<T, List>::operator=(instance);
  return (*this);
}

// member functions
template <typename T, typename List>
typename MutantStack<T, List>::iterator MutantStack<T, List>::begin(void) {
  return (this->c.begin());
}

template <typename T, typename List>
typename MutantStack<T, List>::iterator MutantStack<T, List>::end(void) {
  return (this->c.end());
}

template <typename T, typename List>
typename MutantStack<T, List>::reverse_iterator MutantStack<T, List>::rbegin(void) {
  return (this->c.rbegin());
}

template <typename T, typename List>
typename MutantStack<T, List>::reverse_iterator MutantStack<T, List>::rend(void) {
  return (this->c.rend());
}
