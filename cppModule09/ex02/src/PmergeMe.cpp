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
void	printOrder(std::vector<int>& order)
{
	for (size_t i = 0; i < order.size(); i++) {
		std::cout << "Order = " << order[i] << " | ";
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
std::vector<int> PmergeMe::buildInsertionOrder(size_t pendingSize)
{
	std::vector<size_t> jacob = limitsJacobsthal(pendingSize);
	std::vector<int> order;

	printJacob(jacob);
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

void PmergeMe::sortPairsRecursive(std::vector<Pair>& pairs) {
    // Caso base: si hay 1 o 0 parejas, ya están ordenadas
    if (pairs.size() <= 1) {
        return;
    }

    // 1. Dividir las parejas en dos grupos para ordenarlas de forma recursiva
    // Creamos un vector para los elementos de la cadena principal en este nivel de parejas
    std::vector<Pair> mainChainPairs;
    std::vector<Pair> pendingPairs;

    // Emparejamos las parejas existentes de dos en dos y comparamos sus valores '.big'
    for (size_t i = 0; i + 1 < pairs.size(); i += 2) {
        if (pairs[i].big > pairs[i + 1].big) {
            std::swap(pairs[i], pairs[i + 1]);
        }
        pendingPairs.push_back(pairs[i]);      // La pareja con el '.big' menor es "pending"
        mainChainPairs.push_back(pairs[i + 1]);  // La pareja con el '.big' mayor va a la "main chain"
    }

    // Guardar la pareja huérfana si el número de parejas actuales es impar
    bool hasStragglerPair = (pairs.size() % 2 != 0);
    Pair stragglerPair;
    if (hasStragglerPair) {
        stragglerPair = pairs.back();
    }

    // 2. LLAMADA RECURSIVA: Ordenar la cadena principal de parejas
    sortPairsRecursive(mainChainPairs);

    // 3. Generar el orden de inserción de Jacobsthal para las parejas pendientes
    std::vector<int> order = buildInsertionOrder(pendingPairs.size());

    // La primera pareja pendiente siempre se inserta al principio de la cadena principal de parejas gratis
    if (!pendingPairs.empty()) {
        mainChainPairs.insert(mainChainPairs.begin(), pendingPairs[0]);
    }

    // Insertar el resto de parejas utilizando Jacobsthal y búsqueda binaria acotada
	for (size_t k = 1; k < order.size(); k++) {
    	size_t index = order[k];
    	Pair currentPair = pendingPairs[index];

    // Buscamos manualmente el límite superior para C++98 sin usar lambda ni find_if
    	std::vector<Pair>::iterator limite = mainChainPairs.end();
    	for (std::vector<Pair>::iterator it = mainChainPairs.begin(); it != mainChainPairs.end(); ++it) {
    	    if (it->big == currentPair.big) {
    	        limite = it;
    	        break;
    	    }
    	}

    	// Para el lower_bound de estructuras en C++98, definimos la comparación con una función tradicional
    	// o simplemente usamos un bucle o una función auxiliar. Aquí usamos lower_bound con iterador explícito
    	// pero necesitamos pasarle un objeto de comparación o hacerlo manualmente si no queremos crear un functor.
    
    	// Forma C++98 limpia usando un bucle de inserción directa para evitar problemas de plantillas con estructuras:
    	std::vector<Pair>::iterator pos = mainChainPairs.begin();
    	while (pos != limite && pos->big < currentPair.big) {
    	    ++pos;
    	}

    mainChainPairs.insert(pos, currentPair);
}

    // 4. Insertar la pareja huérfana si existía
	if (hasStragglerPair) {
    	std::vector<Pair>::iterator pos = mainChainPairs.begin();
    	while (pos != mainChainPairs.end() && pos->big < stragglerPair.big) {
    	    ++pos;
    	}
    	mainChainPairs.insert(pos, stragglerPair);
	}

    // Devuelve el vector de parejas completamente ordenado por el valor '.big'
    pairs = mainChainPairs;
}
void PmergeMe::mergeInsertVector(std::vector<int>& data)
{
	if (data.size() <= 1)
		return ;

	std::vector<Pair> pair;

	for (size_t i = 0; i + 1 < data.size(); i += 2) {
		Pair pairs;
		if (data[i] > data[i + 1])
			std::swap(data[i], data[i + 1]);
		pairs.small = data[i];
		pairs.big = data[i + 1];
		pair.push_back(pairs);
	}

	bool hasStraggler = (data.size() % 2 != 0);
    int straggler = hasStraggler ? data.back() : 0;

	sortPairsRecursive(pair);

	std::vector<int> mainChain;
	std::vector<Pair> pending;

	for (size_t i = 0; i < pair.size(); i++) {
		pending.push_back(pair[i]);
		mainChain.push_back(pair[i].big);
	}
	if (!pending.empty())
        mainChain.insert(mainChain.begin(), pending[0].small);

	std::vector<int> order = buildInsertionOrder(pending.size());
	printOrder(order);
	mergeInsertVector(mainChain);

	for (size_t k = 1; k < order.size(); k++) {
		size_t index = order[k];
		Pair elementoActual = pending[index];

		std::vector<int>::iterator limiteSuperior = std::find(mainChain.begin(), mainChain.end(), elementoActual.big);
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), limiteSuperior, elementoActual.small);
		mainChain.insert(pos, elementoActual.small);
		//std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[index]);
		//mainChain.insert(pos, pending[index]);
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