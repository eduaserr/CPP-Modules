#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(const RPN& other){*this = other;}
RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
		_stack = other._stack;
	return *this;
}
RPN::~RPN(){}

bool RPN::isNumber(const std::string& token) const {
	return (token.size() == 1 && std::isdigit(token[0]));
}
bool RPN::isOperator(const std::string& token) const {
	return (token.size() == 1 && (token[0] == '+' || token[0] == '-' ||
			token[0] == '*' || token[0] == '/'));
}
void RPN::executeOperation(char symbol)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error");

	int b = _stack.top();
	_stack.pop();

	int a = _stack.top();
	_stack.pop();

	int result;

	switch (symbol)
	{
		case '+':
			result = a + b;
			break ;

		case '-':
			result = a - b;
			break ;

		case '*':
			result = a * b;
			break ;

		case '/':
			if (b == 0)
				throw std::runtime_error("Cannot divide 0");
			result = a / b;
			break ;

		default:
			throw std::runtime_error("Error");
	}

	_stack.push(result);
}
void RPN::processInput(const std::string &str) {
	std::stringstream ss(str);
	std::string token;

	while (ss >> token)
	{
 		if (isNumber(token))
 			_stack.push(token[0] - '0');
		else if (isOperator(token))
			executeOperation(token[0]);
		else
			throw std::runtime_error("Error");
	}
	if (_stack.size() != 1)
			throw std::runtime_error("Error");

std::cout << _stack.top() << std::endl;
}

void RPN::printStack() const
{
	std::stack<int> tmp = _stack;

	std::cout << "Top" << std::endl;

	while (!tmp.empty())
	{
		std::cout << "| " << tmp.top() << " |" << std::endl;
		tmp.pop();
	}

	std::cout << "Bottom" << std::endl;
}