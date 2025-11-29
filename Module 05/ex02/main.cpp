/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:57:32 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/29 17:10:33 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <sstream>

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

int main(void) {
	std::cout << MAGENTA << "=== TEST 1: ShrubberyCreationForm SUCCESS ===" << RESET << std::endl;
	try {
		Bureaucrat alice("Alice", 100);
		ShrubberyCreationForm shrub("park");
		std::cout << shrub << std::endl;
		alice.signForm(shrub);
		std::cout << shrub << std::endl;
		alice.executeForm(shrub);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << MAGENTA << "\n=== TEST 2: RobotomyRequestForm SUCCESS ===" << RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 40);
		RobotomyRequestForm robot("Bender");
		std::cout << robot << std::endl;
		bob.signForm(robot);
		bob.executeForm(robot);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << MAGENTA << "\n=== TEST 3: PresidentialPardonForm SUCCESS ===" << RESET << std::endl;
	try {
		Bureaucrat charlie("Charlie", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << pardon << std::endl;
		charlie.signForm(pardon);
		charlie.executeForm(pardon);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << MAGENTA << "\n=== TEST 4: EXECUTE WITHOUT SIGNING ===" << RESET << std::endl;
	try {
		Bureaucrat dave("Dave", 1);
		ShrubberyCreationForm shrub2("garden");
		std::cout << "[ Attempting to execute unsigned form ]" << std::endl;
		dave.executeForm(shrub2);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << MAGENTA << "\n=== TEST 5: GRADE TOO LOW TO EXECUTE ===" << RESET << std::endl;
	try {
		Bureaucrat frank("Frank", 50);
		RobotomyRequestForm robot2("Marvin");
		frank.signForm(robot2);
		std::cout << "[ Frank (grade 50) tries to execute (requires 45)... ]" << std::endl;
		frank.executeForm(robot2);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
