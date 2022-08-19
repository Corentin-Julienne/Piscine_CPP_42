/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:41:49 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/19 12:45:31 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	public:
	
		Form(void);
		Form(std::string const name, unsigned int const grade_sign, unsigned int const grade_exec);
		~Form();
		Form(const Form& original);

		Form&	operator=(const Form& original);
	
		// getters
		std::string const	getName(void) const;
		bool				getSigned(void) const;
		unsigned int const	getGradeSign(void) const;
		unsigned int const	getGradeExec(void) const;
		std::string const	getTarget(void) const;
		// members functions
		void				beSigned(const Bureaucrat& bureaucrat);
		void				execute(Bureaucrat const &executor) const;
		virtual void		action(void) const = 0;
		//  exceptions class
		class GradeTooLowException : public std::exception
		{
			public:

				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:

				const char* what() const throw();
		};

	private:
	
		std::string const 	_name;
		bool				_signed;
		unsigned int const	_grade_sign;
		unsigned int const	_grade_exec;
		std::string	const	_target;
};

std::ostream&	operator<<(std::ostream& stream, const Form& form);

#endif