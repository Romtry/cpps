#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm *Intern::MakeForm(const std::string &name, const std::string &target)
{
	const std::string names[4] = {"Shrubbery", "Robotomy", "Presidential", "NONE"};

	int i;

	for (i = 0; i < 3; i++)
	{
		if (name == names[i])
			break;
	}
	switch (i)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
		{
			std::cout << "no Form named like that" << std::endl;
			return (NULL);
		}
	}
}
