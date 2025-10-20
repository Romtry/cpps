/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:13:55 by rothiery          #+#    #+#             */
/*   Updated: 2025/08/11 12:47:19 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>

class AForm;

class Bureaucrat
{
	public:
							Bureaucrat(const std::string &Name, short grade);
							Bureaucrat(const Bureaucrat &original);
							~Bureaucrat();
		std::string			getName() const;
		short				getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm &f) const;
		void				executeForm(const AForm & form) const;

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
		const std::string	_name;
		short				_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
