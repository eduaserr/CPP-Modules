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

void	PmergeMe::printJacob(const std::vector<size_t>& Jacob) const
{
	for (size_t i = 0; i < Jacob.size(); i++) {
		std::cout << "Jacob [" << i << "] = " << Jacob[i] << " | ";
	}
	std::cout << std::endl;
}
void	PmergeMe::printData(const std::vector<int>& data) const
{
	for (size_t i = 0; i < data.size(); i++) {
		std::cout << "data [" << i << "] = " << data[i] << " | ";
	}
	std::cout << std::endl;
}
void	PmergeMe::printMain(const std::vector<int>& main) const
{
	for (size_t i = 0; i < main.size(); i++) {
		std::cout << "MainChain [" << i << "] = " << main[i] << " | ";
	}
	std::cout << std::endl;
}
void	PmergeMe::printPend(const std::vector<int>& pend) const
{
	for (size_t i = 0; i < pend.size(); i++) {
		std::cout << "Pending  [" << i << "] = " << pend[i] << " | ";
	}
	std::cout << std::endl;
}
void	PmergeMe::printOrder(const std::vector<int>& oder) const
{
	for (size_t i = 0; i < oder.size(); i++) {
		std::cout << "Oder  [" << i << "] = " << oder[i] << " | ";
	}
	std::cout << std::endl;
}
void PmergeMe::printPairs(const std::vector<Pair>& pairs) const
{
	std::cout << "Pairs:" << std::endl;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		std::cout
			<< "  [" << i << "] "
			<< "  small=" << pairs[i].small
			<< "  big=" << pairs[i].big
			<< std::endl;
	}

	std::cout << std::endl;
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

static std::vector<size_t> limitsJacobsthal(size_t size) {
	std::vector<size_t> jacob;
	jacob.push_back(1); // J(1)
	jacob.push_back(1); // J(2)

	// Generar términos hasta que el número supere la cantidad de elementos en B
	int i = 2;
	while (jacob.back() < size_t(size)) {
		int next = jacob[i - 1] + 2 * jacob[i - 2];
		jacob.push_back(next);
		i++;
	}
	return jacob; // Contiene por ejemplo: 1, 1, 3, 5, 11, 21...
}
std::vector<int> PmergeMe::buildInsertionOrder(const std::vector<int> &pending) const
{
	size_t pendSize = pending.size();
	std::vector<int> order;
	std::vector<size_t> jacob = limitsJacobsthal(pendSize);

	printJacob(jacob);

	if (pendSize <= 1)
		return order;
	size_t prev = 1;

	for (size_t j = 2; j < jacob.size(); j++) {
		size_t current = jacob[j];
		if (current > pendSize)
			current = pendSize;

		while (current > prev)
		{
			order.push_back(current - 1); // pasar de b1,b2... a índice 0,1...
			current--;
		}

		prev = jacob[j];
	}
	return order;
}
static std::vector<Pair> makePairs(std::vector<int> &data) {
	std::vector<Pair> pair;
	for (size_t i = 0; i + 1 < data.size(); i += 2) {
		Pair pairs;
		if (data[i] > data[i + 1])
			std::swap(data[i], data[i + 1]);
		pairs.small = data[i];
		pairs.big = data[i + 1];
		pair.push_back(pairs);
	}
	return (pair);
}

void PmergeMe::sortPending(std::vector<int>& mainChain,std::vector<int>& pending, std::vector<Pair>& pairs)
{
	if (pending.size() <= 1)
		return ;

	std::vector<int> sortedPending;
	std::vector<Pair> sortedPairs;

	for (size_t mainIndex = 0; mainIndex < mainChain.size(); ++mainIndex) {
		for (size_t pairIndex = 0; pairIndex < pairs.size(); ++pairIndex)
		{
			if (pairs[pairIndex].big == mainChain[mainIndex])
			{
				sortedPending.push_back(pairs[pairIndex].small);
				sortedPairs.push_back(pairs[pairIndex]);
				break ;
			}
		}
	}
	pending = sortedPending;
	pairs = sortedPairs;
}

size_t PmergeMe::getPairIndx(const std::vector<int>& pend, size_t jac, const std::vector<Pair>& pairs)
{
	size_t i;
	for (i = 0; i < pairs.size(); ++i) {
		if (pairs[i].small == pend[jac])
			break ;
	}
	return i;
}
size_t PmergeMe::getMainPos(const std::vector<int>& mainChain, const Pair& pair)
{
	size_t i;
	for (i = 0; i < mainChain.size(); ++i) {
		if (mainChain[i] == pair.big)
			break ;
	}
	return i;
}
void PmergeMe::mergeInsertVector(std::vector<int>& data)
{
	if (data.size() <= 1)
		return ;

	std::vector<Pair> pairs = makePairs(data);		// Hago parejas

	bool hasStraggler = (data.size() % 2 != 0);			// compruebo si hay sobrante
	int straggler = hasStraggler ? data.back() : 0;		// lo guardamos

	std::vector<int> mainChain;
	std::vector<int> pending;

	std::cout << " __ Make Pairs __ " << std::endl;

	printPairs(pairs);
	for (size_t i = 0; i < pairs.size(); i++)			//Rellenamos mainChain y pending
	{
		pending.push_back(pairs[i].small);
		mainChain.push_back(pairs[i].big);
	}

	std::cout << " __ Data OG __ " << std::endl;
	
	printData(data);

	std::cout << " __ MAIN CHAIN __ " << std::endl;

	printMain(mainChain);

	std::cout << " __ PENDING __ " << std::endl;

	printPend(pending);


	mergeInsertVector(mainChain);					//LLAMADA RECURSIVA

	std::cout << " == Pos recursive == " << std::endl;
	printMain(mainChain);
	printPend(pending);
	printPairs(pairs);
	std::cout << std::endl;

	std::cout << "\n========== SORT PENDING ==========\n";
	// ENcontrar y mover pending para mantener su relacion/pareja con mainChain
	sortPending(mainChain, pending, pairs);

	std::cout << " == SWAP PEND == " << std::endl;
	printPend(pending);
	std::cout << " == SWAP PAIRS IDX == " << std::endl;
	printPairs(pairs);

	if (straggler)
		std::cout << "stragler is " << straggler << std::endl;
	// if pending sobra uno (No eslo mismo que stragler), buscar el mayor mas cercano por encima de su pareja
	//antes de insertar, tanto el main como pend deben estar ordenados
	if (!pending.empty())
		mainChain.insert(mainChain.begin(), pending[0]);
	std::cout << " == MAIN + INSERT [0] == " << std::endl;
	printMain(mainChain);
	std::vector<int> order = buildInsertionOrder(pending);

	std::cout << " == PEND ORDER == " << std::endl;
	printOrder(order);

	for (size_t i = 0; i < order.size(); i++) {
		size_t jac = order[i];

		std::cout << "\n----------------------------------------" << std::endl;
		std::cout << "ORDER INDEX = " << i << std::endl;
		std::cout << "PENDING INDEX = " << jac << std::endl;
		std::cout << "PENDING VALUE = " << pending[jac] << std::endl;

	// --------------------------------------------------------
	// Buscar la Pair correspondiente
	// --------------------------------------------------------

		size_t j = getPairIndx(pending, jac, pairs);
		if (j == pairs.size()) {
			std::cout << "No pair found" << std::endl;
			continue ;
		}

		std::cout << "PAIR FOUND:" << std::endl;
		std::cout << "small = " << pairs[j].small << std::endl;
		std::cout << "big   = " << pairs[j].big << std::endl;

	// --------------------------------------------------------
	// Buscar la posición de la pareja en mainChain
	// --------------------------------------------------------

		size_t MainPos = getMainPos(mainChain, pairs[j]);
		if (MainPos == mainChain.size())
		{
			std::cout << "Partner not found in mainChain" << std::endl;
			continue ;
		}

		std::cout << "PARTNER POSITION = " << MainPos << std::endl;

	// --------------------------------------------------------
	// BÚSQUEDA BINARIA LIMITADA
	// --------------------------------------------------------

		std::vector<int>::iterator begin = mainChain.begin();
		std::vector<int>::iterator end = mainChain.begin() + MainPos;
		std::vector<int>::iterator pos = std::lower_bound(begin, end, pending[jac]);
		mainChain.insert(pos, pending[jac]);

		std::cout << " __ FINAL MAIN CHAIN __ " << std::endl;
		printMain(mainChain);
	}
	if (straggler) {
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}
	printMain(mainChain);
	data = mainChain;
}
void PmergeMe::mergeInsertDeque(std::deque<int>& data) {

	(void)data;
	//mergeInsertDeque(_deque);
}
void PmergeMe::exec() {

	printBefore();
	std::clock_t startVector = std::clock();
	mergeInsertVector(_vector);
	std::clock_t endVector = std::clock();
	//mergeInsertDeque(_deque);
	printAfter();
	double vectorTime = static_cast<double>(endVector - startVector) * 1000000.0 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : "
	<< vectorTime << " us" << std::endl;
}