/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:49:25 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/16 09:49:03 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << "[DEBUG]" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "[INFO]" << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "[WARNING]" << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "[ERROR]" << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string lvl)
{
	void 		(Harl::*ptr[4])() = {&Harl::error, &Harl::warning, &Harl::info, &Harl::debug};
	const std::string	name[4] = {"ERROR", "WARNING", "INFO", "DEBUG"};
	int					level;

	level = 4;
	for (int i = 0; i < 4; i++)
	{
		if (lvl == name[i])
			level = i;
	}
	switch (level)
	{
		case 0:
		{
			(this->*ptr[level])();
			level++;
		}
		case 1:
		{
			(this->*ptr[level])();
			level++;
		}
		case 2:
		{
			(this->*ptr[level])();
			level++;
		}
		case 3:
		{
			(this->*ptr[level])();
			level++;
		}
		default:
			break;
	}
}
