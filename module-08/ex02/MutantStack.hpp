#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <list>
#include <stack>

// std::list will be the underlying container of std::stack
template <typename T, typename List = std::list<T> >
class MutantStack : public std::stack<T, List> {
 public:
  // constructors and destructors
  MutantStack(void);
  MutantStack(const MutantStack& instance);
  ~MutantStack(void);
  // copy assignment operator overload
  MutantStack& operator=(const MutantStack& instance);
  // typedefs
  typedef typename List::iterator iterator;
  typedef typename List::iterator reverse_iterator;
  // member functions
  iterator begin(void);
  iterator end(void);
  reverse_iterator rbegin(void);
  reverse_iterator rend(void);
};

#include "MutantStack.tpp"

#endif
