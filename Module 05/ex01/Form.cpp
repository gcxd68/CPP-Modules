/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:02:15 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/24 12:16:49 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default constructor
Form::Form(void)
	: _name("unnamed")
	, _isSigned(false)
	, _requiredSignGrade(150)
	, _requiredExecGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

// Parameterized constructor
Form::Form(const std::string& name, unsigned int sign_req, unsigned int exec_req) 
	: _name(name)
	, _isSigned(false)
	, _requiredSignGrade(sign_req)
	, _requiredExecGrade(exec_req)
{
	std::cout << "Form parameterized constructor called" << std::endl;
	if (sign_req < 1 || exec_req < 1)
		throw GradeTooHighException();
	if (sign_req > 150 || exec_req > 150)
		throw GradeTooLowException();
}

// Copy constructor
Form::Form(const Form& other) 
	: _name(other._name)
	, _isSigned(other._isSigned)
	, _requiredSignGrade(other._requiredSignGrade)
	, _requiredExecGrade(other._requiredExecGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

// Copy assignment operator
Form& Form::operator=(const Form& other) {
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

// Destructor
Form::~Form(void) {
	std::cout << "Form destructor called" << std::endl;
}

// Accessor(s)
const std::string& Form::getName(void) const {
	return this->_name;
}

bool Form::getSignedStatus(void) const {
	return this->_isSigned;
}

unsigned int Form::getRequiredSignGrade(void) const {
	return this->_requiredSignGrade;
}

unsigned int Form::getRequiredExecGrade(void) const {
	return this->_requiredExecGrade;
}

// Core method(s)
void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_requiredSignGrade)
		throw GradeTooLowException();
	this->_isSigned = true;
}

// Exception class(es)
const char* Form::GradeTooHighException::what() const throw() {
	return "Form: grade requirement is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form: grade requirement is too low!";
}

// Overload of insertion operator
std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form '" << f.getName() 
		<< "' [Status: " << (f.getSignedStatus() ? "signed" : "unsigned")
		<< ", Sign req: " << f.getRequiredSignGrade()
		<< ", Exec req: " << f.getRequiredExecGrade() << "]";
	return os;
}
