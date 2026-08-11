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



	template <typename Container>
	void printJacob(const Container& jacob) const;
	template <typename Container>
	void printData(const Container& data) const;
	template <typename Container>
	void printMain(const Container& mainChain) const;
	template <typename Container>
	void printPend(const Container& pending) const;
	template <typename Container>
	void printOrder(const Container& order) const;
	template <typename Container>
	void printPairs(const Container& pairs) const;

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
