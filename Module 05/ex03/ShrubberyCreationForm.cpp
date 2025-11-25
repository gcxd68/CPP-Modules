/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:36:10 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/25 13:54:48 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Default shrubbery creation", SIGN_GRADE, EXEC_GRADE)
	, _target("Default")
{}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery creation", SIGN_GRADE, EXEC_GRADE)
	, _target(target)
{}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
	, _target(other._target)
{}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

// Core method(s)
static void printTrees(std::ofstream& outfile) {
	static const char* treeParts[] = {
		"    *   ",
		"   ***  ",
		"  ***** ",
		" *******",
		"    |   "
	};
	for (int lineNum = 0, treeCount = 0; lineNum < 10 && (treeCount < 2 || AForm::coinFlip()); lineNum++) {
		int treesOnLine = 1;
		while (treesOnLine < 10 && ((treeCount < 2 && treesOnLine < 1) || AForm::coinFlip()))
			treesOnLine++;
		for (int line = 0; line < 5; line++) {
			for (int i = 0; i < treesOnLine; i++)
				outfile << treeParts[line];
			outfile << std::endl;
		}
		outfile << std::endl;
		treeCount += treesOnLine;
	}
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getSignedStatus())
		throw FormNotSignedException();
	if (executor.getGrade() > getRequiredExecGrade())
		throw GradeTooLowException();
	std::ofstream outfile((this->_target + "_shrubbery").c_str());
	if (!outfile.is_open())
		throw std::runtime_error("Failed to create file");
	printTrees(outfile);
	outfile.close();
	std::cout
		<< "ASCII trees successfully written to '"
		<< this->_target << "_shrubbery'" << std::endl;
}
