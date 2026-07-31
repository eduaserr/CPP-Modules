#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cerr << "Usage: ./RPN 'operation'" << std::endl, 1);

	try {
		RPN calc;
		calc.processInput(av[1]);
		calc.printStack();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}