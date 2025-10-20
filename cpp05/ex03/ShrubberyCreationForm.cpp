#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
# include "Bureaucrat.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm(target, 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original)
	: AForm("ShrubberyCreationForm", 145, 137)
{
	this->setSign(original.getSign());
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original)
{
	this->setSign(original.getSign());
	std::cout << "ShrubberyCreationForm = operator called" << std::endl;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &b) const
{
	if (this->getSign() == false)
		throw (GradeTooHighException());
	std::cout << "b.grade = " << b.getGrade() << " gradeexec = " << this->getGradeExec() << std::endl;
	if (b.getGrade() > this->getGradeExec())
		throw (GradeExecTooHigh());
	const std::string tmp = b.getName() + "_shrubbery";
	std::ofstream	file;
	file.open(tmp.c_str());
	if (!file.is_open())
	{
		std::cout << "error open file" << std::endl;
		return ;
	}
	std::cout << "tree created" << std::endl;
	file << "	                                                             ............. ......." << std::endl;
	file << "                                                             .......::::--====-..." << std::endl;
	file << "                                                         .......:--===========++-." << std::endl;
	file << "                                                         ...::==============+++..." << std::endl;
	file << "                                                     .....:-==============+++:...." << std::endl;
	file << "                                                     ...:-===========+==+++:.." << std::endl;
	file << "                                                     .::=============++:......" << std::endl;
	file << "                                                 ....:-==============++..." << std::endl;
	file << "                                                 ..::==============++=...." << std::endl;
	file << "        .....................                .....::=======+++=+++++.." << std::endl;
	file << "       ........::::::::......                  ..::=++=======+-......." << std::endl;
	file << "    ....:-===============---:::.......       ....:++++++++***-...." << std::endl;
	file << "    ..++=======================-::...        ...:+++++++++***...." << std::endl;
	file << "    .:*+++=========================:::.........:-++++++++++*+....." << std::endl;
	file << "    .....=++++=+=++=================+-::.......:*++++++++***..." << std::endl;
	file << "    ............:++==================++=::....-:****++**##=..." << std::endl;
	file << "                ..-*++====++++====+++++++=::..:=****###+:..........:::::::::---:......" << std::endl;
	file << "                ......-++-.+*++++**++++++++:::-+***##%:......::::-===-========--==+=:." << std::endl;
	file << "                    ... ......+**+++++++++**-:-*#####+:...::-======================++++=......." << std::endl;
	file << "                      ........:***+++++++****-:*##*###-::-==============+==+=========++*++=...." << std::endl;
	file << "            ........:::::::----:-***##*##*****:-#*#%#-:=+++===+=========+==++===========***++:....." << std::endl;
	file << "            ....:::--==========+++++**++*###***--%#%-=+++++++=++========+++++:+==========+****+:..." << std::endl;
	file << "        .....-=:-============+++++++++****#####+--#=+++++++++++*========+++++..+++=======+*******:.." << std::endl;
	file << "        ...==-===============+*=+++++***#####**#-=++++++*+++++++-*+===+++++++...-++**************#:." << std::endl;
	file << "    .....==+-=====++=+=======+*++++++*****######*=-*++++**++++**..+*++*+++=:......:*******+=-......." << std::endl;
	file << "    ...-+++-======*++++======+.*++++******#*#%###==**+***+*=-::::::::::.......    ..........." << std::endl;
	file << "    ..=+*+-======+.*+**++=++*+.+***#*-+==+*####%##+*******+*++++++=+====-:::..    ........." << std::endl;
	file << ".....++*+--===-++-.=**+******...:-::=*******#####%***#****++++++++++========-:::...." << std::endl;
	file << "....+***=====++*+.....:.......::-=+++++******####%*#******++++++++++==++=======-::...." << std::endl;
	file << "...+****+******+.   .......:.:==+++++++++****######**##****+**+++++=+*+==========-::.. ..." << std::endl;
	file << "..=+****++***=...   .....:::=====+++++++*#***###%#*#*+******=*+++++**==============::-....." << std::endl;
	file << ".:***++=..          ...:::=======+++++++*#**###%%###-#####-.#******:*+==============-:=...." << std::endl;
	file << "......... ...       ..::-========+-*=++*#+*#=+%%##***::.....:+##*=..*+=======+===+====:=..." << std::endl;
	file << "........ ..     .....::-==+======*:****#+....-++++**%:..............***+==++*+++++======+......" << std::endl;
	file << "                ....::====+======*-***#:..   .-++++*##....       ....*********+++=======++....." << std::endl;
	file << "                ...::--===+=====+*-......    .-=++++*%-...       ......:+*****:.+=======*++...." << std::endl;
	file << "                ..::--====+====++*:..        ..-+++*###...            ..........*+======+++:..." << std::endl;
	file << "                .::---====+==+++*-...        ..==+++##%-..            .........:**+======*++..." << std::endl;
	file << "                .::---==-=+*++**:            ..:-+++*##*..                    ..****=====**+:.." << std::endl;
	file << "                ::----===++*##:..            ...-=+++##%:...                  ..=*****===**+=.." << std::endl;
	file << "            ....::---==+*+*=.               ....--+++*##=.                    ....**********+.." << std::endl;
	file << "            ....:-=-==++**#..                ...:-+++*###.                    ......+*******+.." << std::endl;
	file << "            ....:-====++*-*..                ....-+++####-....                ... ....:*****+.." << std::endl;
	file << "            ....:====+++#....                ....=+*#####+....                        ...-***.." << std::endl;
	file << "           .....:===++*#+....                 ....*######%....                        ........." << std::endl;
	file << "            ....:-=++**-.                        .+++++*##-..." << std::endl;
	file << "            .....-=**#:..                        .+++++**#*..." << std::endl;
	file << "                .-+*#....                        .*++++**#%..." << std::endl;
	file << "                ..+*.....                        .=+++***#%..." << std::endl;
	file << "                                                 .-++*+**%-..." << std::endl;
	file << "                                                 .-++**##%%*.." << std::endl;
	file << "                                                 .-++**###%#.." << std::endl;
	file << "                                                 .=+++**##%%.." << std::endl;
	file << "                                                 .=++***###@:." << std::endl;
	file << "                                                 .++++**###%-." << std::endl;
	file << "                                                 .+++***###%=." << std::endl;
	file << "                                             ....=++++****#%+." << std::endl;
	file << "                                             ....##****####%*." << std::endl;
	file << "                                             ....+++++*####%*." << std::endl;
	file << "                                             ...-+++++*####%#." << std::endl;
	file << "                                             ...=+++**+####%#." << std::endl;
	file << "                                             ...-+++***###%%#." << std::endl;
	file << "                                             ..==++*+**###%%+." << std::endl;
	file << "                                             .:-++++*####%%%%." << std::endl;
	file << "                                             .-=+++++*#####%%=" << std::endl;
	file << "                                         ....--+++++++####%%%+" << std::endl;
	file << "                                         ...--++++++**####%%%+" << std::endl;
	file << "                                         ..--=++++++*#####%%%=" << std::endl;
	file << "                                         .--=+++++++*#####%%@-" << std::endl;
	file << "                                         :-=++++++++######%%=." << std::endl;
	file << "                                         ...-*+++++*####-....." << std::endl;
	file << "                                      .. .......  ............" << std::endl;
	file.close();
}
