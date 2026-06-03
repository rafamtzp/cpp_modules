#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data some_data;
	some_data.data = 42;
	Data	*ptr = &some_data;

	std::cout << "ptr: " << ptr << std::endl;

	uintptr_t serialized = Serializer::serialize(ptr);
	std::cout << "Serialized ptr: " << serialized << std::endl;

	Data	*deserialized = Serializer::deserialize(serialized);
	std::cout << "deserialized serialized ptr: " << deserialized << std::endl;

	std::cout << deserialized->data << std::endl;
}