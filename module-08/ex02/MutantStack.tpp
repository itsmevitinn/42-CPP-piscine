#include "MutantStack.hpp"

// constructors and destructors
template <typename T, typename Deque>
MutantStack<T, Deque>::MutantStack(void) : std::stack<T, Deque>() {
}

template <typename T, typename Deque>
MutantStack<T, Deque>::MutantStack(const MutantStack<T, Deque>& instance) : std::stack<T, Deque>(instance) {
}

template <typename T, typename Deque>
MutantStack<T, Deque>::~MutantStack(void) {
}

// copy assignment operator overload
template <typename T, typename Deque>
MutantStack<T, Deque>& MutantStack<T, Deque>::operator=(const MutantStack<T, Deque>& instance) {
  if (this != &instance)
    std::stack<T, Deque>::operator=(instance);
  return (*this);
}

// member functions
template <typename T, typename Deque>
typename MutantStack<T, Deque>::iterator MutantStack<T, Deque>::begin(void) {
  return (this->c.begin());
}

template <typename T, typename Deque>
typename MutantStack<T, Deque>::iterator MutantStack<T, Deque>::end(void) {
  return (this->c.end());
}

template <typename T, typename Deque>
typename MutantStack<T, Deque>::reverse_iterator MutantStack<T, Deque>::rbegin(void) {
  return (this->c.rbegin());
}

template <typename T, typename Deque>
typename MutantStack<T, Deque>::reverse_iterator MutantStack<T, Deque>::rend(void) {
  return (this->c.rend());
}
