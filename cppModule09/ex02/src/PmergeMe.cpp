#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe& data){(void)data;}
PmergeMe& PmergeMe::operator=(const PmergeMe& data){
	if (this != &data) {
		_vector = data._vector;
		_deque = data._deque;
	}
	return (*this);
}
PmergeMe::~PmergeMe(){}
