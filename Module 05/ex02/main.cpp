/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:57:32 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/20 13:57:45 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <sstream>

#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int main(void) {
	std::cout << CYAN << "=== Test 1: ShrubberyCreationForm ===" << RESET << std::endl;
	try {
		Bureaucrat alice("Alice", 100);
		ShrubberyCreationForm shrub("home");
		
		std::cout << shrub << std::endl;
		alice.signForm(shrub);
		std::cout << shrub << std::endl;
		alice.executeForm(shrub);
	}
	catch (std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 2: RobotomyRequestForm Success ===" << RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 40);
		RobotomyRequestForm robot("Bender");
		
		std::cout << robot << std::endl;
		bob.signForm(robot);
		bob.executeForm(robot);
	}
	catch (std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 3: PresidentialPardonForm ===" << RESET << std::endl;
	try {
		Bureaucrat charlie("Charlie", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		
		std::cout << pardon << std::endl;
		charlie.signForm(pardon);
		charlie.executeForm(pardon);
	}
	catch (std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 4: Execute without signing ===" << RESET << std::endl;
	try {
		Bureaucrat dave("Dave", 1);
		ShrubberyCreationForm shrub2("garden");
		
		std::cout << YELLOW << "Attempting to execute unsigned form..." << RESET << std::endl;
		dave.executeForm(shrub2);
	}
	catch (std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 5: Grade too low to execute ===" << RESET << std::endl;
	try {
		Bureaucrat eve("Eve", 100);
		Bureaucrat frank("Frank", 50);
		RobotomyRequestForm robot2("Marvin");
		
		eve.signForm(robot2);
		std::cout << YELLOW << "Frank (grade 50) tries to execute (requires 45)..." << RESET << std::endl;
		frank.executeForm(robot2);
	}
	catch (std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 6: Grade too low to sign ===" << RESET << std::endl;
	try {
		Bureaucrat grace("Grace", 30);
		PresidentialPardonForm pardon2("Ford Prefect");
		
		std::cout << YELLOW << "Grace (grade 30) tries to sign (requires 25)..." << RESET << std::endl;
		grace.signForm(pardon2);
	}
	catch (std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 7: Multiple robotomy attempts (50% success rate) ===" << RESET << std::endl;
	try {
		Bureaucrat henry("Henry", 1);
		
		for (int i = 0; i < 5; i++) {
			std::stringstream ss;
			ss << "Target_" << i;
			RobotomyRequestForm robot(ss.str());
			henry.signForm(robot);
			henry.executeForm(robot);
			std::cout << std::endl;
		}
	}
	catch (std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 8: Create multiple shrubbery files ===" << RESET << std::endl;
	try {
		Bureaucrat ivan("Ivan", 1);
		
		ShrubberyCreationForm tree1("forest");
		ShrubberyCreationForm tree2("park");
		ShrubberyCreationForm tree3("backyard");
		
		ivan.signForm(tree1);
		ivan.signForm(tree2);
		ivan.signForm(tree3);
		
		ivan.executeForm(tree1);
		ivan.executeForm(tree2);
		ivan.executeForm(tree3);
		
		std::cout << GREEN << "Check your directory for: forest_shrubbery, park_shrubbery, backyard_shrubbery" << RESET << std::endl;
	}
	catch (std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 9: Presidential pardon for multiple targets ===" << RESET << std::endl;
	try {
		Bureaucrat president("President", 1);
		
		PresidentialPardonForm pardon1("Zaphod");
		PresidentialPardonForm pardon2("Trillian");
		
		president.signForm(pardon1);
		president.signForm(pardon2);
		
		president.executeForm(pardon1);
		president.executeForm(pardon2);
	}
	catch (std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "\n=== All tests completed ===" << RESET << std::endl;
}
