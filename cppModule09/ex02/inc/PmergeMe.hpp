#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>

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

	std::vector<size_t> buildInsertionOrderVec(const size_t pendSize) const;
	std::deque<size_t> buildInsertionOrderDq(size_t pendSize) const;

	template <typename Container, typename Pairs>
	void sortPending(Container& mainChain, Container& pending, Pairs& pairs);

	template <typename Container, typename Pairs>
	size_t getPairIndx(const Container& pend, size_t jac, const Pairs& pairs);
	template <typename Container>
	size_t getMainPos(const Container& mainChain, const Pair& pair);

	void mergeInsertVector(std::vector<int>& data);
	void mergeInsertDeque(std::deque<int>& data);

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
