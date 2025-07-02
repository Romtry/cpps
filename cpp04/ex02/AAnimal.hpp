/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:13:29 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/26 14:18:31 by rothiery         ###   ########.fr       */
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
		Animal			&operator=(Animal &original);
		std::string		getType();
		virtual void	makeSound() = 0;

	protected:
		std::string	type;
};
