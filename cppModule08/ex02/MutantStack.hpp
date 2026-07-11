#ifndef MutantStack_HPP
#define MutantStack_HPP

#include <iostream>
#include <string>
#include <stack>

template <typename T>
class MutantStack :  public std::stack<T> {
private:

public:

	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack(){};
	~MutantStack(){};

	iterator begin() { return this->c.begin(); }

	iterator end() { return this->c.end(); }
};

#endif