#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <cstdlib>
#include <ctime>

struct Pair
{
    int small;
    int big;
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
	void sortPairsRecursive(std::vector<Pair>& pairs);
	void mergeInsertVector(std::vector<int>& data);
	void mergeInsertDeque(std::deque<int>& data);
	std::vector<int> buildInsertionOrder(size_t pendingSize);
	void printBefore() const;
	void printAfter() const;
};

#endif
