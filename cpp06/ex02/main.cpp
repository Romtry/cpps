//
// Created by rothiery on 9/23/25.
//

#include "Base.hpp"
#include "Utils.hpp"

int main()
{
	Base* base = generate();
	identify(*base);
	identify(base);
}
