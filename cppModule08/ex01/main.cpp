#include "Span.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

/*int main()
{
	Span sp(100);

	std::vector<int> v;

	std::srand(std::time(NULL));

	for (int i = 0; i < 100; i++)
		v.push_back(std::rand());

	try
	{
		sp.addNumbers(v.begin(), v.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}*/


int main()
{
	Span sp(5);

	std::vector<int> v;

	sp.addNumber(INT_MIN);
	sp.addNumber(INT_MAX);

	try
	{
		sp.addNumbers(v.begin(), v.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}