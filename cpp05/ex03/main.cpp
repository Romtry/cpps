#include "Intern.hpp"

int	main()
{
	Intern	intern;

	const AForm	*form1 = intern.MakeForm("Shrubbery", "Form");
	const AForm	*form2 = intern.MakeForm("Robotomy", "Some Form");
	const AForm	*form3 = intern.MakeForm("Presidential", "Other Form");
	const AForm	*form4 = intern.MakeForm("hello world", "Wrong Form");

	delete (form1);
	delete (form2);
	delete (form3);
	delete (form4);

	return (0);
}
