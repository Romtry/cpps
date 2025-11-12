//
// Created by rothiery on 10/17/25.
//

#include  "BitcoinExchange.hpp"

int	main(const int argc, char **argv)
{
	if (argc != 2)
		std::cout << "wrong args: ./btc <file.csv>" << std::endl;
	try
	{
		BitcoinExchange test;
		test.Init();
		test.Exec(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}