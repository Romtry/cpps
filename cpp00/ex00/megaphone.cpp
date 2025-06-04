#include <iostream>

int	main(int argc, char **argv)
{
	std::string	str;

	if (!argv[1])
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; argv[i]; i++)
		str += argv[i];
	(void)argc;
	for (int i = 0; str[i]; i++)
		str[i] = std::toupper(str[i]);
	std::cout << str << std::endl;
	return (0);
}
