#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
	Array<int> ints(3);
	for (unsigned int i = 0; i < ints.size(); ++i)
		ints[i] = static_cast<int>(i + 1);

	Array<std::string> strings(2);
	strings[0] = "hello";
	strings[1] = "world";

	Array<int> copy(ints);
	copy[0] = 42;

	std::cout << "ints[0] = " << ints[0] << std::endl;
	std::cout << "copy[0] = " << copy[0] << std::endl;
	std::cout << "strings[0] = " << strings[0] << std::endl;
	std::cout << "strings[1] = " << strings[1] << std::endl;

	try
	{
		std::cout << ints[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}