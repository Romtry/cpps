/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:19:26 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/19 13:53:14 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Brain
{
	public:
		Brain();
		Brain(Brain &original);
		~Brain();
		Brain	operator=(Brain &original);

	protected:
		std::string	ideas[100];
};
