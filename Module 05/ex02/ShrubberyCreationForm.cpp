/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:36:10 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/20 13:56:47 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getSignedStatus())
		throw FormNotSignedException();
	if (executor.getGrade() > getRequiredExecGrade())
		throw GradeTooLowException();

	std::ofstream outfile((_target + "_shrubbery").c_str());
	outfile << "    *\n";
	outfile << "   ***\n";
	outfile << "  *****\n";
	outfile << " *******\n";
	outfile << "    |\n";
	outfile.close();
}
