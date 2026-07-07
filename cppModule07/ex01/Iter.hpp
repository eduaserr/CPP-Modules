#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>
#include <string>

template <typename T>
void iter(T *array, std::size_t length, void (*func)(T const &))
{
	if (!array || !func)
		return;
	for (std::size_t i = 0; i < length; ++i)
		func(array[i]);
}

template <typename T>
void printElement(T const &value)
{
	std::cout << value << std::endl;
}

#endif