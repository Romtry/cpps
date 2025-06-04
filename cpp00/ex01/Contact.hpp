#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	public:
	Contact();
	void		setFirstName(std::string);
	void		setLastName(std::string);
	void		setNickname(std::string);
	void		setPhoneNumber(std::string);
	void		setDarkestSecret(std::string);
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickame();
	std::string	getPhoneNumber();
	std::string	getDarkestSecret();
	void		existing();
	bool		is_existing();

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
		bool		exist;
};

#endif
