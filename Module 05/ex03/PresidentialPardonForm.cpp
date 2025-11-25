/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:36:14 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/25 13:47:10 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Default presidential pardon", SIGN_GRADE, EXEC_GRADE)
	, _target("Default")
{}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential pardon", SIGN_GRADE, EXEC_GRADE)
	, _target(target)
{}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other)
	, _target(other._target)
{}

// Copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void) {}

// Core method(s)
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->getSignedStatus())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getRequiredExecGrade())
		throw GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
