#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base::~Base() {}

Base *generate(void)
{
	int r = std::rand() % 3;

	if (r == 0)
	{
		std::cout << "Generated class: A\n";
		return new A();
	}
	if (r == 1)
	{
		std::cout << "Generated class: B\n";
		return new B();
	}
	std::cout << "Generated class: C\n";
	return new C();
}

void identify(Base *p)
{
	std::cout << "identify(Base*): ";
	if (dynamic_cast<A *>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C\n";
}

void identify(Base &p)
{
	std::cout << "identify(Base&): ";
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A\n";
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B\n";
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C\n";
		return;
	} catch (...) {}
}