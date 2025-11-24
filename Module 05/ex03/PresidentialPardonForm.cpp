/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:36:14 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/24 15:14:18 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Default Presidential Pardon", 25, 5)
	, _target("Default")
{}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardon", 25, 5)
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
	if (!getSignedStatus())
		throw FormNotSignedException();
	if (executor.getGrade() > getRequiredExecGrade())
		throw GradeTooLowException();
	std::cout << this->_target << " pardoned by Zaphod Beeblebrox" << std::endl;
}
