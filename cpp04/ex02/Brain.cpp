/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:47:20 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/26 10:21:34 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(Brain &original)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = original.ideas[i];
	}
}

Brain	Brain::operator=(Brain &original)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = original.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructed" << std::endl;
}
