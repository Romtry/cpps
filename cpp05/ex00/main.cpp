#include <iostream>
#include "Bureaucrat.hpp"

void	tryModifyGrade(const std::string name, short grade, char modifyGrade)
{
	try
	{
		Bureaucrat	test(name, grade);
		if (modifyGrade == '+')
			test.incrementGrade();
		else if (modifyGrade == '-')
			test.decrementGrade();
		std::cout << test << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	tryBureaucrat(const std::string name, short grade)
{
	try
	{
	Bureaucrat	test(name, grade);
		std::cout << test << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main()
{
	tryBureaucrat("Toto", 42);
	tryBureaucrat("Tata", 1);
	tryBureaucrat("Titi", 150);
	tryBureaucrat("WrongToto", -42);
	tryBureaucrat("WrongTata", 0);
	tryBureaucrat("WrongTiti", 151);

	tryModifyGrade("Decrease", 42, '-');
	tryModifyGrade("Increase", 42, '+');
	tryModifyGrade("WrongDecrease", 150, '-');
	tryModifyGrade("WrongIncrease", 1, '+');

	return (0);
}

class main
{
	public:
			main();
			main(main &original);
			~main();
		main	&operator=(main &original);

	protected:
		
	private:
		
};
