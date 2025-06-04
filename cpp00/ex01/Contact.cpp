#include "Contact.hpp"

Contact::Contact()
{
	exist = false;
}

bool Contact::is_existing()
{
	return (exist);
}

void Contact::existing()
{
	exist = true;
}

void Contact::setFirstName(std::string str)
{
	_first_name = str;
}

void Contact::setLastName(std::string str)
{
	_last_name = str;
}

void Contact::setNickname(std::string str)
{
	_nickname = str;
}

void Contact::setPhoneNumber(std::string str)
{
	_phone_number = str;
}

void Contact::setDarkestSecret(std::string str)
{
	_darkest_secret = str;
}

std::string	Contact::getFirstName()
{
	return (_first_name);
}

std::string	Contact::getLastName()
{
	return(_last_name);
}

std::string	Contact::getNickame()
{
	return (_nickname);
}

std::string	Contact::getPhoneNumber()
{
	return (_phone_number);
}

std::string	Contact::getDarkestSecret()
{
	return (_darkest_secret);
}
