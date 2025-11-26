#include "RPN.hpp"

int main(const int argc, const char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong input: ./RPN \"equation\"" << std::endl;
		return (1);
	}
	RPN	tmp;
	tmp.exec(argv[1]);
}