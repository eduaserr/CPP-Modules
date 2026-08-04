#include "inc/PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << "Usage: ./PmergeMe numbers..." << std::endl;
		return 1;
	}

	try
	{
		PmergeMe pmerge;
		pmerge.processInput(av + 1);
		pmerge.exec();
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}