#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& a, int value)
{
	typename T::iterator i = std::find(a.begin(), a.end(), value);
	if (i == a.end())
		throw std::runtime_error("Value not found");
	return i;
}