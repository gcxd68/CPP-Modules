/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:48:49 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/25 13:09:38 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

// Helper method(s)
AForm* Intern::createShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

// Default constructor
Intern::Intern(void) {
	std::cout << "Intern default constructor called" << std::endl;
}

// Copy constructor
Intern::Intern(const Intern&) {
	std::cout << "Intern copy constructor called" << std::endl;
}

// Copy assignment operator
Intern& Intern::operator=(const Intern&) {
	std::cout << "Intern copy assignment operator called" << std::endl;
	return *this;
}

// Destructor
Intern::~Intern(void) {
	std::cout << "Intern destructor called" << std::endl;
}

// Core method(s)
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (Intern::*formCreators[3])(const std::string&) = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};
	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formCreators[i])(target);
		}
	}
	std::cout << "Error: Form '" << formName << "' does not exist" << std::endl;
	return NULL;
}
