#include "serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& data) { (void)data; }
Serializer& Serializer::operator=(const Serializer& data) { (void)data; return *this; }
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}