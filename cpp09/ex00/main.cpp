//
// Created by rothiery on 10/17/25.
//

#include  "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "need a file" << std::endl;
	for (unsigned int i = 1; argv[i]; i++)
	{
		try
		{
			BitcoinExchange test(argv[i]);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

	}
}