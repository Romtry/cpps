/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:13:55 by rothiery          #+#    #+#             */
/*   Updated: 2025/07/15 10:10:02 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat
{
	public:
							Bureaucrat(std::string &Name, short grade);
							Bureaucrat(Bureaucrat &original);
							~Bureaucrat();
		std::string			getName();
		short				getGrade();
		void				GradeTooHighException();
		void				GradeTooLowException();

	protected:
		
	private:
		const std::string	Name;
		short				Grade;
};
