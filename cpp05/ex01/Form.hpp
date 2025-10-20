//
// Created by rothiery on 8/25/25.
//

#pragma		once
#include	"Bureaucrat.hpp"
# include	<iostream>

class Bureaucrat;

class Form
{
	public:
		Form(const std::string &name, short grade_sign, short grade_exec);
		Form(const Form &original);
		~Form();

		std::string			getName() const;
		short				getGradeSign() const;
		short				getGradeExec() const;
		bool				getSign() const;
		void				beSigned(const Bureaucrat &b);
		class				GradeTooHighException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
		class				GradeTooLowException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

	private:
		bool				_signed;
		const int			_grade_sign;
		const int			_grade_exec;
		const std::string	_name;
};
std::ostream &operator<<(std::ostream &os, const Form &f);
