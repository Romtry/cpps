#pragma		once

# include	<iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm(const std::string &name, short grade_sign, short grade_exec);
		AForm(const AForm &original);
		virtual ~AForm();

		std::string			getName() const;
		short				getGradeSign() const;
		short				getGradeExec() const;
		bool				getSign() const;
		void				setSign(const bool s);
		void				beSigned(const Bureaucrat &b);
		virtual void		execute(const Bureaucrat &b) const = 0;
		class				FormNotSign : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class				GradeExecTooHigh : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
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
		std::string _name;
};
std::ostream &operator<<(std::ostream &os, const AForm &f);
