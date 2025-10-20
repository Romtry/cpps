#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Grade to Sign: 25
// Grade to Execute: 5
// void	tryPresidential(const std::string &name, const short grade, const bool sign)
// {
// 	std::cout << "---" << std::endl;
// 	try
// 	{
// 		Bureaucrat				test(name, grade);
// 		PresidentialPardonForm form(name);
//
// 		if (sign)
// 			test.signForm(form);
// 		test.executeForm(form);
// 	}
// 	catch(const std::exception &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// }
//
// // Grade to Sign: 72
// // Grade to Execute: 45
void	tryRobotomy(const std::string &name, const short grade, const bool sign)
{
	std::cout << "---" << std::endl;
	try
	{
		Bureaucrat			test(name, grade);
		RobotomyRequestForm	form(name);

		if (sign)
			test.signForm(form);
		test.executeForm(form);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// Grade to Sign: 145
// Grade to Execute: 137

// void	tryShrubbery(const std::string& name, const short grade, const bool sign)
// {
// 	std::cout << "---" << std::endl;
// 	try
// 	{
// 		const Bureaucrat				test(name, grade);
// 		ShrubberyCreationForm form(name);
//
// 		if (sign)
// 			test.signForm(form);
// 		test.executeForm(form);
// 	}
// 	catch(const std::exception &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// }

int	main()
{
	// std::cout << "=== Shrubbery ===" << std::endl;
	// tryShrubbery("Toto", 137, true);
	// tryShrubbery("Tata", 145, true);
	// tryShrubbery("Titi", 150, true);
	// tryShrubbery("Tutu", 1, false);

	std::cout << "\n=== Robotomy ===" << std::endl;
	tryRobotomy("Toto", 45, true);
	tryRobotomy("Tata", 72, true);
	tryRobotomy("Titi", 150, true);
	tryRobotomy("Tutu", 1, false);
	//
	// std::cout << "\n=== Presidential ===" << std::endl;
	// tryPresidential("Toto", 5, true);
	// tryPresidential("Tata", 25, true);
	// tryPresidential("Titi", 150, true);
	// tryPresidential("Tutu", 1, false);

	return (0);
}
