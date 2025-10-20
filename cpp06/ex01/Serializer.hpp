//
// Created by rothiery on 9/23/25.
//

#pragma once

# include "data.hpp"
# include <stdint.h>

class Serializer
{
	public:
		static uintptr_t	serialize(t_data *ptr);
		static t_data		*deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer &other);
		~Serializer();
		Serializer	&operator=(const Serializer &other);
};
