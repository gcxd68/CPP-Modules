/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:02:15 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/29 17:15:56 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default constructor
Form::Form(void)
	: _name("unnamed")
	, _isSigned(false)
	, _reqSignGrade(LOWEST_GRADE)
	, _reqExecGrade(LOWEST_GRADE)
{
	std::cout << "Form default constructor called" << std::endl;
}

// Parameterized constructor
Form::Form(const std::string& name, unsigned int reqSignGrade, unsigned int reqExecGrade)
	: _name(name)
	, _isSigned(false)
	, _reqSignGrade(reqSignGrade)
	, _reqExecGrade(reqExecGrade)
{
	std::cout << "Form parameterized constructor called" << std::endl;
	if (reqSignGrade < HIGHEST_GRADE || reqExecGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (reqSignGrade > LOWEST_GRADE || reqExecGrade > LOWEST_GRADE)
		throw GradeTooLowException();
}

// Copy constructor
Form::Form(const Form& other)
	: _name(other._name)
	, _isSigned(other._isSigned)
	, _reqSignGrade(other._reqSignGrade)
	, _reqExecGrade(other._reqExecGrade)
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

unsigned int Form::getReqSignGrade(void) const {
	return this->_reqSignGrade;
}

unsigned int Form::getReqExecGrade(void) const {
	return this->_reqExecGrade;
}

// Core method(s)
void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_reqSignGrade)
		throw GradeTooLowException();
	this->_isSigned = true;
}

// Exception class(es)
const char* Form::GradeTooHighException::what() const throw() {
	return "the grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "the grade is too low";
}

// Overload of insertion operator
std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form '" << f.getName() 
		<< "' [Status: " << (f.getSignedStatus() ? "signed" : "unsigned")
		<< ", Sign req: " << f.getReqSignGrade()
		<< ", Exec req: " << f.getReqExecGrade() << "]";
	return os;
}
