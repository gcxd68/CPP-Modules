/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:02:15 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/20 13:58:07 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
	: _name("unnamed")
	, _isSigned(false)
	, _requiredSignGrade(150)
	, _requiredExecGrade(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, unsigned int sign_req, unsigned int exec_req) 
	: _name(name)
	, _isSigned(false)
	, _requiredSignGrade(sign_req)
	, _requiredExecGrade(exec_req)
{
	std::cout << "AForm parameterized constructor called" << std::endl;
	if (sign_req < 1 || exec_req < 1)
		throw GradeTooHighException();
	if (sign_req > 150 || exec_req > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) 
	: _name(other._name)
	, _isSigned(other._isSigned)
	, _requiredSignGrade(other._requiredSignGrade)
	, _requiredExecGrade(other._requiredExecGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm(void) {
	std::cout << "Form destructor called" << std::endl;
}

const std::string& AForm::getName(void) const {
	return this->_name;
}

bool AForm::getSignedStatus(void) const {
	return this->_isSigned;
}

unsigned int AForm::getRequiredSignGrade(void) const {
	return this->_requiredSignGrade;
}

unsigned int AForm::getRequiredExecGrade(void) const {
	return this->_requiredExecGrade;
}

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_requiredSignGrade)
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form: grade requirement is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form: grade requirement is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Cannot execute: form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << "Form '" << f.getName() 
		<< "' [Status: " << (f.getSignedStatus() ? "signed" : "unsigned")
		<< ", Sign req: " << f.getRequiredSignGrade()
		<< ", Exec req: " << f.getRequiredExecGrade() << "]";
	return os;
}
