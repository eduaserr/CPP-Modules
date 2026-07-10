#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <string>

class Span {
private:
	std::vector<int> _numbers;
	unsigned int _N;

public:
	Span(unsigned int N);

	void	addNumber(int number);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	template <typename Iterator>
	void	addNumbers(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			addNumber(*begin);
			++begin;
		}
	}

	class throwException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return "Max size reached";
		}
	};
	class NotEnoughException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Not enough numbers";
		}
	};
};

#endif