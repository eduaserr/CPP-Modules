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

std::vector<int> limitsJacobsthal(int size) {
	std::vector<int> jacob;
	jacob.push_back(1); // J(1)
	jacob.push_back(1); // J(2)

	// Generar términos hasta que el número supere la cantidad de elementos en B
	int i = 2;
	while (jacob.back() < size) {
		int next = jacob[i - 1] + 2 * jacob[i - 2];
		jacob.push_back(next);
		i++;
	}
	return jacob; // Contiene por ejemplo: 1, 1, 3, 5, 11, 21...
}
std::vector<size_t> PmergeMe::buildInsertionOrder(size_t pendingSize)
{
	std::vector<int> jacob = limitsJacobsthal(pendingSize);
	std::vector<size_t> order;

	// siempre se inserta el primero
	if (pendingSize > 0)
		order.push_back(0);

	size_t prev = 1;

	for (size_t j = 2; j < jacob.size(); j++)
	{
		size_t current = std::min((size_t)jacob[j], pendingSize);

		while (current > prev)
		{
			order.push_back(current - 1); // pasar de b1,b2... a índice 0,1...
			current--;
		}

		prev = jacob[j];
	}

	return order;
}

void	printOrder(std::vector<size_t>& order)
{
	for (size_t i = 0; i < order.size(); i++) {
		std::cout << "Order = " << order[i] << " | ";
	}
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
	std::vector<size_t> order = buildInsertionOrder(pending.size());
	printOrder(order);
	mergeInsertVector(mainChain);

	for (size_t k = 0; k < order.size(); k++) {
		size_t index = order[k];

		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[index]);
		mainChain.insert(pos, pending[index]);
	}

	if ((data.size() % 2 != 0)) {
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