/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:57:32 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/25 13:08:12 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

int main(void) {
	std::cout << MAGENTA << "=== TEST 1: INTERN CREATES ROBOTOMY REQUEST ===" << RESET << std::endl;
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf) {
			std::cout << *rrf << std::endl;
			delete rrf;
		}
	}
	std::cout << MAGENTA << "\n=== TEST 2: INTERN CREATES SHRUBBERY CREATION ===" << RESET << std::endl;
	{
		Intern intern;
		AForm* form;
		form = intern.makeForm("shrubbery creation", "home");
		if (form) {
			std::cout << *form << std::endl;
			delete form;
		}
	}
	std::cout << MAGENTA << "\n=== TEST 3: INTERN CREATES PRESIDENTIAL PARDON ===" << RESET << std::endl;
	{
		Intern intern;
		AForm* form;
		form = intern.makeForm("presidential pardon", "Arthur Dent");
		if (form) {
			std::cout << *form << std::endl;
			delete form;
		}
	}
	std::cout << MAGENTA << "\n=== TEST 4: INVALID FORM NAME ===" << RESET << std::endl;
	{
		Intern intern;
		AForm* form;
		form = intern.makeForm("invalid form", "target");
		if (!form)
			std::cout << "[ Form creation failed as expected ]" << std::endl;
	}
	std::cout << MAGENTA << "\n=== TEST 5: COMPLETE WORKFLOW ===" << RESET << std::endl;
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
}
