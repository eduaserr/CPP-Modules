#include "Iter.hpp"
#include <string>

int main()
{
	int ints[] = { 1, 2, 3, 4 };
	std::string strings[] = { "one", "two", "three" };

	std::cout << "=== int array ===" << std::endl;
	iter(ints, 4, printElement<int>);

	std::cout << std::endl << "=== string array ===" << std::endl;
	iter(strings, 3, printElement<std::string>);

	return 0;
}