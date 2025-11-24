/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:58:02 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/24 15:35:26 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

// Default constructor
Bureaucrat::Bureaucrat(void)
	: _name("Unknown")
	, _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name)
{
	std::cout << "Bureaucrat parameterized constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name)
	, _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}	

// Destructor
Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

// Accessor(s)
const std::string& Bureaucrat::getName(void) const {
	return this->_name;
}

unsigned int Bureaucrat::getGrade(void) const {
	return this->_grade;
}

// Core method(s)
void Bureaucrat::incrementGrade(void) {
	if (this->_grade <= 1)
		throw GradeTooHighException();
	std::cout << "Incrementing " << this->_name << "'s grade" << std::endl;
	this->_grade--;
}

void Bureaucrat::decrementGrade(void) {
	if (this->_grade >= 150)
		throw GradeTooLowException();
	std::cout << "Decrementing " << this->_name << "'s grade" << std::endl;
	this->_grade++;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << this->_name << " couldn't sign " << form.getName() 
			<< ": " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << this->_name << " couldn't execute " << form.getName() 
			<< ": " << e.what() << std::endl;
	}
}

// Exception implementation(s)
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

// Insertion operator overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}
