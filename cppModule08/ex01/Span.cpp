#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {
	_numbers.reserve(N);
}

void	Span::addNumber(int number) {
	if (_numbers.size() >= _N)
		throw throwException();
	this->_numbers.push_back(number);
}

unsigned int	Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw NotEnoughException();
	
	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());
	int span = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size(); i++) {
		int dif = tmp[i] - tmp[i - 1];
		span = std::min(span, dif);
	}
	return span;
}

unsigned int	Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw NotEnoughException();

	int min = _numbers[0];
	int max = _numbers[0];
	for (size_t i = 1; i < _numbers.size(); i++) {
		min = std::min(min, _numbers[i]);
		max = std::max(max, _numbers[i]);
	}
	return max - min;
}
