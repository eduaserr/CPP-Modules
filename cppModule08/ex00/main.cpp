#include "easyfind.hpp"
#include <iostream>
#include <string>
#include <vector>

int main()
{
	try
	{
		std::vector<int> v;
		for (int i; i < 10; i++){
			v.push_back(i);
		}
		std::vector<int>::iterator it = easyfind(v, 4);
		std::cout << *it << std::endl;
		it = easyfind(v, 2);
		std::cout << *it << std::endl;
		it = easyfind(v, 42);
		std::cout << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}