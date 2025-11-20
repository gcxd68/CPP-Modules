/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:58:06 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/20 11:11:20 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

int main(void) {
	std::cout << MAGENTA << "=== Test 1: Valid bureaucrat ===" << RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << MAGENTA << "\n=== Test 2: Grade too high ===" << RESET << std::endl;
	try {
		Bureaucrat alice("Alice", 0);
		std::cout << alice << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << MAGENTA << "\n=== Test 3: Grade too low ===" << RESET << std::endl;
	try {
		Bureaucrat charlie("Charlie", 151);
		std::cout << charlie << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << MAGENTA << "\n=== Test 4: Increment grade ===" << RESET << std::endl;
	try {
		Bureaucrat dave("Dave", 2);
		std::cout << dave << std::endl;
		dave.incrementGrade();
		std::cout << dave << std::endl;
		std::cout << "[ Trying to increment Dave's grade past 1 ]" << std::endl;
		dave.incrementGrade();
		std::cout << dave << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << MAGENTA << "\n=== Test 5: Decrement grade ===" << RESET << std::endl;
	try {
		Bureaucrat eve("Eve", 149);
		std::cout << eve << std::endl;
		eve.decrementGrade();
		std::cout << eve << std::endl;
		std::cout << "[ Trying to decrement Eve's grade past 150 ]" << std::endl;
		eve.decrementGrade();
		std::cout << eve << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
