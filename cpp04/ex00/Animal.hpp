/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:13:29 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/19 11:06:46 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
	public:
						Animal();
						Animal(std::string type);
						Animal(Animal &original);
						~Animal();
		Animal			operator=(Animal &original);
		std::string		getType();
		virtual void	makeSound();

	protected:
		std::string	type;
};
