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

#include <iostream>

class Bureaucrat
{
	public:
							Bureaucrat(const std::string &Name, short grade);
							Bureaucrat(const Bureaucrat &original);
							~Bureaucrat();
		std::string			getName();
		short				getGrade();
		void				incrementGrade();
		void				decrementGrade();


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

std::ostream &operator<<(std::ostream &os, Bureaucrat b);
