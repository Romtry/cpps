/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:13:29 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/19 14:48:51 by rothiery         ###   ########.fr       */
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
		virtual			~Animal();
		Animal			operator=(Animal &original);
		std::string		getType();
		virtual void	makeSound();

	protected:
		std::string	type;
};
