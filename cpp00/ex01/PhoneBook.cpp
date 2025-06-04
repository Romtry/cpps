#include "PhoneBook.hpp"

bool	verif_input(std::string str, int func(int))
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (func(str[i]) == false)
			return (false);
	}
	if (i == 0)
		return (false);
	return (true);
}

bool	get_firstname(std::string *firstName)
{
	std::cout << "enter firstName\n";
	if (!std::getline(std::cin, *firstName))
		return (false);
	while (verif_input(*firstName, isalpha) == false)
	{
		std::cout << "firstName should only have letters try again\n";
		if (!std::getline(std::cin, *firstName))
		{
			std::cout << "Terminated...\n";
			return (false);
		}
		if ((*firstName)[0] == 0)
			std::getline(std::cin, *firstName);
	}
	return (true);
}

bool	get_lastname(std::string *lastName)
{
	std::cout << "enter lastName\n";
	if (!std::getline(std::cin, *lastName))
		return (false);
	while (verif_input(*lastName, isalpha) == false)
	{
		std::cout << "lastName should only have letters try again\n";
		std::getline(std::cin, *lastName);
		if ((*lastName)[0] == 0)
			std::getline(std::cin, *lastName);
		if (std::cin.eof())
		{
			std::cout << "Terminated...\n";
			return (false);
		}
	}
	return (true);
}

bool	get_nickname(std::string *nickName)
{
	std::cout << "enter nickName\n";
	if (!std::getline(std::cin, *nickName))
		return (false);
	while (verif_input(*nickName, isalpha) == false)
	{
		std::cout << "nickName should only have letters try again\n";
		std::getline(std::cin, *nickName);
		if ((*nickName)[0] == 0)
			std::getline(std::cin, *nickName);
		if (std::cin.eof())
		{
			std::cout << "Terminated...\n";
			return (false);
		}
	}
	return (true);
}

bool get_number(std::string *number)
{
	std::cout << "enter number\n";
	if (!std::getline(std::cin, *number))
		return (false);
	while (verif_input(*number, isdigit) == false)
	{
		std::cout << "number should only have numbers try again\n";
		if (!std::getline(std::cin, *number))
		{
			std::cout << "Terminated...\n";
			return (false);
		}
		if ((*number)[0] == 0)
			std::getline(std::cin, *number);
	}
	return (true);
}

bool	get_secret(std::string *secret)
{
	std::cout << "enter secret\n";
	if (!std::getline(std::cin, *secret))
		return (false);
	while ((*secret).length() == 0)
	{
		std::cout << "secret can't be empty try again\n";
		if (!std::getline(std::cin, *secret))
		{
			std::cout << "Terminated...\n";
			return (false);
		}
		if ((*secret)[0] == 0)
			std::getline(std::cin, *secret);
	}
	return (true);
}

void	move_all(Contact contacts[8])
{
	unsigned int	i;

	i = 0;
	while (i < 7)
	{
		contacts[i].setFirstName(contacts[i + 1].getFirstName());
		contacts[i].setLastName(contacts[i + 1].getLastName());
		contacts[i].setNickname(contacts[i + 1].getNickame());
		contacts[i].setPhoneNumber(contacts[i + 1].getPhoneNumber());
		contacts[i].setDarkestSecret(contacts[i + 1].getDarkestSecret());
		i++;
	}
}

void	PhoneBook::add(void)
{
	static int	i = 0;
	std::string	firstName;
	std::string	name;
	std::string	nickname;
	std::string	number;
	std::string	secret;

	if (!get_firstname(&firstName))
		return ;
	if (!get_lastname(&name))
		return ;
	if (!get_nickname(&nickname))
		return ;
	if (!get_number(&number))
		return ;
	if (!get_secret(&secret))
		return ;
	if (i == 7 && contacts[i].is_existing() == true)
		move_all(contacts);
	contacts[i].setFirstName(firstName);
	contacts[i].setLastName(name);
	contacts[i].setNickname(nickname);
	contacts[i].setPhoneNumber(number);
	contacts[i].setDarkestSecret(secret);
	contacts[i].existing();
	if (i < 7)
		i++;
}

void	search_util(std::string str)
{
	if (str.length() <= 10)
		std::cout << "|" << std::setw(10) << str;
	else
		std::cout << "|" << str.substr(0, 9) << ".";
}

void	print_contact(Contact contact)
{
	std::cout << contact.getFirstName() << "\n";
	std::cout << contact.getLastName() << "\n";
	std::cout << contact.getNickame() << "\n";
	std::cout << contact.getPhoneNumber() << "\n";
	std::cout << contact.getDarkestSecret() << "\n";
}

void	PhoneBook::search()
{
	int			index;
	std::string	input;

	for (index = 0; index < 8 && contacts[index].is_existing() == true; index++)
	{
		std::cout << "|" << std::setw(10) << index;
		search_util(contacts[index].getFirstName());
		search_util(contacts[index].getLastName());
		search_util(contacts[index].getNickame());
		std::cout << "|\n";
	}
	if (index == 0)
	{
		std::cout << "No contact\n";
		return ;
	}
	std::cout << "Enter index\n";
	while (1)
	{
		if (!std::getline(std::cin, input))
		{
			std::cout << "Terminated...\n";
			break ;
		}
		if (input[1] || input[0] - '0' >= index || input[0] - '0' < 0)
			std::cout << "Input not between 0 and " << index - 1 << "\n";
		else
		{
			print_contact(contacts[input[0] - '0']);
			break  ;
		}
	}
}
