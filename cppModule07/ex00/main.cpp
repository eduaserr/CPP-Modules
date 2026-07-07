#include "Whatever.hpp"
#include <iostream>
#include <string>

int main()
{
	int a = 2;
	int b = 3;

	std::cout << "=== int tests ===" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << std::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << std::max(a, b) << std::endl;
	swap(a, b);
	std::cout << "after swap -> a = " << a << ", b = " << b << std::endl;

	std::string c = "str1";
	std::string d = "str2";

	std::cout << std::endl << "=== string tests ===" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << std::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << std::max(c, d) << std::endl;
	swap(c, d);
	std::cout << "after swap -> c = " << c << ", d = " << d << std::endl;

	return 0;
}