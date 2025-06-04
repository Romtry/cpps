/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:42:59 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/16 09:33:03 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::string		replace;

	if (argc != 4)
	{
		std::cout << "wrong args : filename s1 s2" << std::endl;
		return (0);
	}
	infile.open(argv[1]);
	if (!infile)
	{
		std::cout << "Wrong file path" << std::endl;
		return (0);
	}
	replace = argv[1];
	replace += ".replace";
	std::ofstream outfile(replace.c_str());
	outfile << rplace(argv[2], argv[3], infile);
	infile.close();
	return (0);
}
