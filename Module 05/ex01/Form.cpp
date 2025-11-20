/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:02:15 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/20 11:53:45 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("unnamed"), _is_signed(false), _required_sign_grade(150), _required_exec_grade(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, unsigned int sign_req, unsigned int exec_req) 
	: _name(name), _is_signed(false), _required_sign_grade(sign_req), _required_exec_grade(exec_req) {
	std::cout << "Form parameterized constructor called" << std::endl;
	if (sign_req < 1 || exec_req < 1)
		throw GradeTooHighException();
	if (sign_req > 150 || exec_req > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) 
	: _name(other._name), _is_signed(other._is_signed), 
	  _required_sign_grade(other._required_sign_grade), _required_exec_grade(other._required_exec_grade) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other)
		this->_is_signed = other._is_signed;
	return *this;
}

Form::~Form(void) {
	std::cout << "Form destructor called" << std::endl;
}

const std::string&	Form::getName(void) const {
	return this->_name;
}

bool	Form::getSignedStatus(void) const {
	return this->_is_signed;
}

unsigned int	Form::getRequiredSignGrade(void) const {
	return this->_required_sign_grade;
}

unsigned int	Form::getRequiredExecGrade(void) const {
	return this->_required_exec_grade;
}

void	Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_required_sign_grade)
		throw GradeTooLowException();
	this->_is_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Form: grade requirement is too high!";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Form: grade requirement is too low!";
}

std::ostream&	operator<<(std::ostream& os, const Form& f) {
	os << "Form '" << f.getName() 
	   << "' [Status: " << (f.getSignedStatus() ? "signed" : "unsigned")
	   << ", Sign req: " << f.getRequiredSignGrade()
	   << ", Exec req: " << f.getRequiredExecGrade() << "]";
	return os;
}
