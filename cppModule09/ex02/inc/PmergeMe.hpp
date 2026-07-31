#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe {
private:
	std::vector<int> _vector;
	std::deque<int>  _deque;

public:
	PmergeMe();
	PmergeMe(const PmergeMe& data);
	PmergeMe& operator=(const PmergeMe& data);
	~PmergeMe();

	void processInput(char **av);
};

#endif
