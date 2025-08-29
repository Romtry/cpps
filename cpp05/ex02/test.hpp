#pragma once

class test
{
	public:
		test();

		test(test &original);

		~test();

		test &operator=(test &original);
};