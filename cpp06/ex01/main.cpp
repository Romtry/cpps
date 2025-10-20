//
// Created by rothiery on 9/23/25.
//

# include "Serializer.hpp"
# include <iostream>

int main()
{
	t_data	data;

	data.Str = "Hello World";
	data.Num = 42;
	data.Char = 'F';

	std::cout << "--- Default Data Values ---" << std::endl;
	std::cout << "Address: " << &data.Str << " | Value: " << data.Str << std::endl;
	std::cout << "Address: " << &data.Num << " | Value: " << data.Num << std::endl;
	std::cout << "Address: " << static_cast<void *>(&data.Char) << " | Value: " << data.Char << std::endl;

	const uintptr_t	serializedData = Serializer::serialize(&data);
	const t_data	*deserializeData = Serializer::deserialize(serializedData);

	std::cout << "\n--- Deserialized Data Values ---" << std::endl;
	std::cout << "Address: " << &deserializeData->Str << " | Value: " << deserializeData->Str << std::endl;
	std::cout << "Address: " << &deserializeData->Num << " | Value: " << deserializeData->Num << std::endl;
	std::cout << "Address: " << (void *)&deserializeData->Char << " | Value: " << deserializeData->Char << std::endl;

	std::cout << "\nAddress of Default Data:      " << &data << std::endl;
	std::cout << "Address of Deserialized Data: " << deserializeData << std::endl;

	return (0);
}