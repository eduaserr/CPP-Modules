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

void	printJacob(std::vector<size_t>& Jacob)
{
	for (size_t i = 0; i < Jacob.size(); i++) {
		std::cout << "Jacob [" << i << "] = " << Jacob[i] << " | ";
	}
	std::cout << std::endl;
}
void	printdata(std::vector<int>& data)
{
	for (size_t i = 0; i < data.size(); i++) {
		std::cout << "data [" << i << "] = " << data[i] << " | ";
	}
	std::cout << std::endl;
}
void	printMain(std::vector<int>& main)
{
	for (size_t i = 0; i < main.size(); i++) {
		std::cout << "MainChain [" << i << "] = " << main[i] << " | ";
	}
	std::cout << std::endl;
}
void	printPend(std::vector<int>& pend)
{
	for (size_t i = 0; i < pend.size(); i++) {
		std::cout << "Pending  [" << i << "] = " << pend[i] << " | ";
	}
	std::cout << std::endl;
}
void	printOrder(std::vector<int>& oder)
{
	for (size_t i = 0; i < oder.size(); i++) {
		std::cout << "Oder  [" << i << "] = " << oder[i] << " | ";
	}
	std::cout << std::endl;
}
void	printPairs(std::vector<Pair> &p)
{
	for (size_t i = 0; i < p.size(); i++) {
		std::cout << "pairs big  [" << i << "] = " << p[i].big << " | ";
		std::cout << "pairs small [" << i << "] = " << p[i].small << " | ";
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

std::vector<size_t> limitsJacobsthal(int size) {
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
std::vector<int> PmergeMe::buildInsertionOrder(std::vector<int> &mainChain, std::vector<int> &pending)
{
	(void)mainChain;
	size_t pendSize = pending.size();

	std::vector<int> order;

	std::vector<size_t> jacob = limitsJacobsthal(pendSize);

	printJacob(jacob);

	if (pendSize <= 1)
        return order;
	size_t prev = 1;

	for (size_t j = 2; j < jacob.size(); j++)
	{
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
std::vector<Pair> makePairs(std::vector<int> &data) {
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
void sortPending(std::vector<int>& mainChain, std::vector<int>& pending, std::vector<Pair>& pairs)
{
	for (size_t i = 0; i < pending.size(); i++) {
		size_t j = 0;
		while (j < pairs.size()){
			if (pending[i] == pairs[j].small) 	// encontrar indx pequeño en lista
				break ;
			j++;
		}

		if (j == pairs.size())
			std::cout << "No pair found in insert pend" << std::endl;
	
		std::cout << "S in pend. iter j is " << j << " | ";
	
		size_t k;
		for (k = 0; k < mainChain.size(); k++){		// encontrar indx pareja del pequeño en mainChain
			if (mainChain[k] == pairs[j].big)
				break ;
		}
		if (k == mainChain.size())
			std::cout << "No pair found in mainChain" << std::endl;
		std::cout << "S in main. iter k is " << k << std::endl;
		if (k != mainChain.size()){
			std::swap(pending[k], pending[i]);
		}
	}
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
	
	printdata(data);

	std::cout << " __ MAIN CHAIN __ " << std::endl;

	printMain(mainChain);

	std::cout << " __ PENDING __ " << std::endl;

	printPend(pending);


	mergeInsertVector(mainChain);					//LLAMADA RECURSIVA

	std::cout << " == Pos recursive == " << std::endl;
	printMain(mainChain);
	printPend(pending);
	std::cout << std::endl;

	// ENcontrar y mover pending para mantener su relacion/pareja con mainChain
	sortPending(mainChain, pending, pairs);

	std::cout << " == SWAP PEND == " << std::endl;
	printPend(pending);

	if (straggler)
		std::cout << "stragler is " << straggler << std::endl;
	// if pending sobra uno (No eslo mismo que stragler), buscar el mayor mas cercano por encima de su pareja
	
	if (!pending.empty())
		mainChain.insert(mainChain.begin(), pending[0]);
	std::vector<int> order = buildInsertionOrder(mainChain, pending);

	std::cout << " == PEND ORDER == " << std::endl;
	printOrder(order);

	if (order.size() <= 1)
		return ;
	for (size_t i = 1; i < pending.size(); i++){
		size_t j = 0;
		size_t in = order[i];
		std::cout << order[i] << std::endl;
		std::cout << in << std::endl;

		while (j < pairs.size())
		{
			if (pairs[j].small == pending[in])
				break ;
			j++;
		}
		if (j == pairs.size()) {
			std::cout << "No pair found" << std::endl;
			std::cout << pending[in] << std::endl;
			std::cout << "j failed in "<< j << std::endl;
			continue ;
		}
			std::cout << "i is "<< i << std::endl;
			std::cout << "j is "<< j << std::endl;


		std::vector<int>::iterator it = find(mainChain.begin(), mainChain.end(), pairs[j].big);	// se tiene que poder buscar mas rapido la posicion
		std::cout << "pair for " << pending[in] << " is " << *it << " = " << pairs[j].big << std::endl;
		//mainChain.insert(it, pending[i]);
	}





	if (straggler) {
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
	std::clock_t startVector = std::clock();
	mergeInsertVector(_vector);
	std::clock_t endVector = std::clock();
	//mergeInsertDeque(_deque);
	printAfter();
	double vectorTime = static_cast<double>(endVector - startVector) * 1000000.0 / CLOCKS_PER_SEC;
	std::cout
    << "Time to process a range of "
    << _vector.size()
    << " elements with std::vector : "
    << vectorTime
    << " us"
    << std::endl;
}