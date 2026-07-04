#include "Serializer.hpp"
#include <iostream>

int main() {
	Data d;
	d.id = 42;
	d.name = "Bender";
	d.value = 3.14;

	Data* original = &d;
	uintptr_t raw = Serializer::serialize(original);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "original: " << original << "\n";
	std::cout << "restored: " << restored << "\n";
	std::cout << "equal: " << (original == restored ? "YES" : "NO") << "\n";

	return 0;
}