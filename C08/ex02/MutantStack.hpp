#ifndef MUTANT_STACK_H
# define MUTANT_STACK_H

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
  public:
    MutantStack();
    MutantStack(MutantStack const& rhs);
    MutantStack& operator=(MutantStack const& rhs);
    ~MutantStack();

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
};

#include "MutantStack.tpp"

#endif
