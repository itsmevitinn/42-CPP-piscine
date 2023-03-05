#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <deque>
#include <stack>

template <typename T, typename Deque = std::deque<T> >
// specifying std::deque (could be a vector or list) to be the underlying container of std::stack (if nothing is specified, underlying container is std::deque)
class MutantStack : public std::stack<T, Deque> {
 public:
  // constructors and destructors
  MutantStack(void);
  MutantStack(const MutantStack& instance);
  ~MutantStack(void);
  // copy assignment operator overload
  MutantStack& operator=(const MutantStack& instance);
  // iterator must be from std::deque because we setted the underlying container to be std::deque
  typedef typename Deque::iterator iterator;
  typedef typename Deque::reverse_iterator reverse_iterator;
  // member functions
  iterator begin(void);
  iterator end(void);
  reverse_iterator rbegin(void);
  reverse_iterator rend(void);
};

#include "MutantStack.tpp"

#endif
