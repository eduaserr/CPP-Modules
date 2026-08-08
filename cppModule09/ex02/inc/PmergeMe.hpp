#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <algorithm>

struct Pair
{
    int small;
    int big;
	size_t id;
};

class PmergeMe {
private:
	std::vector<int>	_vector;
	std::deque<int>		_deque;

public:
	PmergeMe();
	PmergeMe(const PmergeMe& data);
	PmergeMe& operator=(const PmergeMe& data);
	~PmergeMe();

	int parseNumber(const std::string& str) const;
	void processInput(char **av);
	void exec();
	void mergeInsertVector(std::vector<int>& data);
	void mergeInsertDeque(std::deque<int>& data);
	std::vector<int> buildInsertionOrder(std::vector<int> &mainChain, std::vector<int> &pending);
	void printBefore() const;
	void printAfter() const;
};

#endif
