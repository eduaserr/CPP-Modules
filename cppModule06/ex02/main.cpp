#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(0));

	Base *p = generate();
	identify(p);
	identify(*p);

	delete p;
	return 0;
}