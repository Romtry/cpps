#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class	PhoneBook
{
	public:
	Contact contacts[8];
	void	add();
	void	search();

	private:
};

#endif
