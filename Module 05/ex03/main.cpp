/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:57:32 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/24 15:55:03 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int main(void) {
	std::cout << CYAN << "=== TEST 1: Intern creates robotomy request ===" << RESET << std::endl;
	{
		Intern someRandomIntern;
		AForm* rrf;
		
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf) {
			std::cout << *rrf << std::endl;
			delete rrf;
		}
	}

	std::cout << CYAN << "\n=== TEST 2: Intern creates shrubbery creation ===" << RESET << std::endl;
	{
		Intern intern;
		AForm* form;
		
		form = intern.makeForm("shrubbery creation", "home");
		if (form) {
			std::cout << *form << std::endl;
			delete form;
		}
	}

	std::cout << CYAN << "\n=== TEST 3: Intern creates presidential pardon ===" << RESET << std::endl;
	{
		Intern intern;
		AForm* form;
		
		form = intern.makeForm("presidential pardon", "Arthur Dent");
		if (form) {
			std::cout << *form << std::endl;
			delete form;
		}
	}

	std::cout << CYAN << "\n=== TEST 4: Invalid form name ===" << RESET << std::endl;
	{
		Intern intern;
		AForm* form;
		
		form = intern.makeForm("invalid form", "target");
		if (!form) {
			std::cout << RED << "Form creation failed as expected" << RESET << std::endl;
		}
	}

	std::cout << CYAN << "\n=== TEST 5: Complete workflow ===" << RESET << std::endl;
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		AForm* form;
		
		form = intern.makeForm("robotomy request", "Employee");
		if (form) {
			std::cout << *form << std::endl;
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}

	std::cout << CYAN << "\n=== TEST 6: Multiple forms from same intern ===" << RESET << std::endl;
	{
		Intern intern;
		Bureaucrat alice("Alice", 1);
		
		AForm* forms[3];
		forms[0] = intern.makeForm("shrubbery creation", "garden");
		forms[1] = intern.makeForm("robotomy request", "Bob");
		forms[2] = intern.makeForm("presidential pardon", "Charlie");
		
		for (int i = 0; i < 3; i++) {
			if (forms[i]) {
				alice.signForm(*forms[i]);
				alice.executeForm(*forms[i]);
				delete forms[i];
			}
		}
	}
}
