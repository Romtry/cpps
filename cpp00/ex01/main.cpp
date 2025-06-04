#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	input;

	std::cout << "Enter command : ADD, SEARCH, EXIT\n";
	while (1)
	{
		if (!std::getline(std::cin, input))
		{
			std::cout << "Terminated...\n";
			break ;
		}
		if (input[0] == 0)
		{
			std::cout << "Wrong input : ADD, SEARCH, EXIT\n";
			continue;
		}
		if (input != "ADD" && input != "SEARCH" && input != "EXIT")
		{
			std::cout << "Wrong input : ADD, SEARCH, EXIT\n";
			continue;
		}
		else if (input == "ADD")
			phoneBook.add();
		else if (input == "SEARCH")
			phoneBook.search();
		else if (input == "EXIT")
			break ;
		std::cout << "Enter command : ADD, SEARCH, EXIT\n";
	}
}
