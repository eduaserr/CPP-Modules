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

static bool checkDigit(const std::string& str)
{
	if (str.empty())
		return false;

	for (size_t i = 0; i < str.size(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}
int PmergeMe::parseNumber(const std::string& str) const
{
	if (!checkDigit(str))
		throw std::runtime_error("Error");

	long value = std::atol(str.c_str());
	if (value > INT_MAX || value <= 0)
		throw std::runtime_error("Error");

	return static_cast<int>(value);
}
void PmergeMe::processInput(char **av)
{
	int number;

	while (*av)
	{
		number = parseNumber(*av);

		_vector.push_back(number);
		_deque.push_back(number);

		av++;
	}
}

void PmergeMe::printBefore() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";

	std::cout << std::endl;
}
void PmergeMe::printAfter() const
{
	std::cout << "After: ";
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";

	std::cout << std::endl;
}

void PmergeMe::mergeInsertVector(std::vector<int>& data)
{
	if (data.size() <= 1)
		return;

	for (size_t i = 0; i + 1 < data.size(); i += 2) {
		if (data[i] > data[i + 1])
			std::swap(data[i], data[i + 1]);
	}

	int straggler = 0;
	if ((data.size() % 2 != 0))
		straggler = data.back();

	std::vector<int> mainChain;
	std::vector<int> pending;

	for (size_t i = 0; i + 1 < data.size(); i += 2) {
		pending.push_back(data[i]);
		mainChain.push_back(data[i + 1]);
	}

	mergeInsertVector(mainChain);

	for (size_t i = 0; i < pending.size(); i++) {
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);

		mainChain.insert(pos, pending[i]);
	}

	if ((data.size() % 2 != 0))
	{
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	data = mainChain;
}
void PmergeMe::mergeInsertDeque(std::deque<int>& data) {

	(void)data;
	//mergeInsertDeque(_deque);
}
void PmergeMe::exec() {

	printBefore();
	mergeInsertVector(_vector);
	//mergeInsertDeque(_deque);
	printAfter();

}