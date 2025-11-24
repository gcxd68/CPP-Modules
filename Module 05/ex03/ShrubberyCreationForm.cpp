/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:36:10 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/24 15:14:35 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Default Shrubbery Creation", 145, 137)
	, _target("Default")
{}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreation", 145, 137)
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
}
