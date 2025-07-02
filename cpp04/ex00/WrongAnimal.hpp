/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:42:51 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/19 11:50:20 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WAnimal
{
	public:
						WAnimal();
						WAnimal(std::string type);
						WAnimal(WAnimal &original);
						~WAnimal();
		WAnimal			operator=(WAnimal &original);
		std::string		getType();
		void			makeSound();

	protected:
		std::string	type;
};
