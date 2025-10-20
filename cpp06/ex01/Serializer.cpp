//
// Created by rothiery on 9/23/25.
//

#include "Serializer.hpp"

uintptr_t	Serializer::serialize(t_data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

t_data		*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<t_data *>(raw));
}

Serializer::Serializer()
{

}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer::~Serializer()
{

}

Serializer	&Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}
