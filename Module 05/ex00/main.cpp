/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:58:06 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/18 12:58:06 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
	std::cout << "=== Test 1: Valid bureaucrat ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Grade too high ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 0);
		std::cout << alice << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Grade too low ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 151);
		std::cout << charlie << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Increment grade ===" << std::endl;
	try {
		Bureaucrat dave("Dave", 2);
		std::cout << dave << std::endl;
		dave.incrementGrade();
		std::cout << dave << std::endl;
		dave.incrementGrade(); // Should throw
		std::cout << dave << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Decrement grade ===" << std::endl;
	try {
		Bureaucrat eve("Eve", 149);
		std::cout << eve << std::endl;
		eve.decrementGrade();
		std::cout << eve << std::endl;
		eve.decrementGrade(); // Should throw
		std::cout << eve << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
