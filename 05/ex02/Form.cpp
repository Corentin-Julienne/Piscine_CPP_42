/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:41:47 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/01 21:05:09 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// basic constructor

Form::Form(void) : _name("autodestruction"), _gradeSign(32), _gradeExec(13)
{
	this->_signed = false;
}

// constructor with params

Form::Form(std::string const name, std::string const target, unsigned int const gradeSign, unsigned int const gradeExec)
: _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign <= 0 || gradeExec <= 0)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
	this->_signed = false;
}

// destructor

Form::~Form() {}

// copy constructor

Form::Form(const Form& original) : _name(original._name), _gradeSign(original._gradeSign),
_gradeExec(original._gradeExec)
{
	this->_signed = original._signed;
}

// overloading operator =

Form&	Form::operator=(const Form& original)
{
	if (this != &original)
		this->_signed = original._signed;
	return *this;
}

// getters

std::string const	Form::getName(void) const
{
	return this->_name;
}

unsigned int const	Form::getGradeSign(void) const
{
	return this->_gradeSign;
}

unsigned int const	Form::getGradeExec(void) const
{
	return this->_gradeExec;
}

bool	Form::getSigned(void) const
{
	return this->_signed;
}

std::string const	Form::getTarget(void) const
{
	return this->_target;
}

// member function

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->getSigned() == true)
		throw Form::AlreadySignedFormException();
	else if (bureaucrat.getGrade() <= this->_gradeSign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

void	Form::execute(const Bureaucrat& bureaucrat) const
{
	if (this->getSigned() == false)
		throw Form::NotSignedFormException();
	else if (bureaucrat.getGrade() <= this->_gradeExec)
		this->action(); // trigger action
	else
		throw Form::GradeTooLowException();
}

// methods for exception handling for inside classes

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::AlreadySignedFormException::what() const throw()
{
	return ("Form has already be signed by a bureaucrat");
}

const char* Form::NotSignedFormException::what() const throw()
{
	return ("Form need to be signed before being executed");
}

// overloading operator <<

std::ostream&	operator<<(std::ostream& stream, const Form& form)
{
	std::string		sign_status;
	
	if (form.getSigned() == true)
		sign_status = "is signed";
	else
		sign_status = "has not been signed";
	stream << "Form " << form.getName() << " requires a Bureaucrat level " << form.getGradeSign() << " or higher to be signed"
	<< " and a Bureaucrat level " << form.getGradeExec() << " to be executed. Currently, the form " << sign_status << std::endl;
	return (stream);
}
