/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:36:07 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/24 15:14:27 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Default Robotomy Request", 72, 45)
	, _target("Default")
{}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequest", 72, 45)
	, _target(target)
{}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other)
	, _target(other._target)
{}

// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void) {}

// Core method(s)
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getSignedStatus())
		throw FormNotSignedException();
	if (executor.getGrade() > getRequiredExecGrade())
		throw GradeTooLowException();
	std::cout << "Bzzzzzzzz... Whirrrrr... Clank!" << std::endl;
	if (AForm::coinFlip())
		std::cout << _target << " robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomy failed" << std::endl;
}
