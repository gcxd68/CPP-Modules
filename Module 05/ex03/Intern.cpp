/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:48:49 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/24 15:51:29 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Default constructor
Intern::Intern(void) {
	std::cout << "Intern default constructor called" << std::endl;
}

// Copy constructor
Intern::Intern(const Intern& other) {
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

// Copy assignment operator
Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

// Destructor
Intern::~Intern(void) {
	std::cout << "Intern destructor called" << std::endl;
}

// Helper methods
AForm* Intern::createShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

// Core method
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	// Array of form names
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	// Array of function pointers
	AForm* (Intern::*formCreators[3])(const std::string&) = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	// Search for matching form
	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formCreators[i])(target);
		}
	}

	// Form not found
	std::cout << "Error: Form '" << formName << "' does not exist" << std::endl;
	return NULL;
}
