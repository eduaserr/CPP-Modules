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
};

class PmergeMe {
private:
	std::vector<int>	_vector;
	std::deque<int>		_deque;

	int parseNumber(const std::string& str) const;
	std::vector<int> buildInsertionOrder(const std::vector<int> &pending) const;
	void sortPending(std::vector<int>& mainChain,std::vector<int>& pending, std::vector<Pair>& pairs);
	size_t getPairIndx(const std::vector<int>& pend, size_t jac, const std::vector<Pair>& pairs);
	size_t getMainPos(const std::vector<int>& mainChain, const Pair& pair);
	void mergeInsertVector(std::vector<int>& data);
	void mergeInsertDeque(std::deque<int>& data);

	void printJacob(const std::vector<size_t>& jacob) const;
    void printData(const std::vector<int>& data) const;
    void printMain(const std::vector<int>& mainChain) const;
    void printPend(const std::vector<int>& pending) const;
    void printOrder(const std::vector<int>& order) const;
    void printPairs(const std::vector<Pair>& pairs) const;

    void printBefore() const;
    void printAfter() const;

public:
	PmergeMe();
	PmergeMe(const PmergeMe& data);
	PmergeMe& operator=(const PmergeMe& data);
	~PmergeMe();

	void processInput(char **av);
	void exec();
};

#endif
