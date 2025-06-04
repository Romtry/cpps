/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:11:35 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/16 09:33:13 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

std::string	rplace(char *&s1, char *&s2, std::ifstream &infile)
{
	std::string		line;
	unsigned int	i;
	std::string		str;

	while (infile >> line)
	{
		while (line.find(s1) != std::string::npos)
		{
			i = line.find(s1);
			line.erase(i, std::strlen(s1));
			line.insert(i, s2);
		}
		str += line;
	}
	return (str);
}
