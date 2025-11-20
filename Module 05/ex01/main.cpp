/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:58:06 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/20 11:54:15 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

int main(void) {
	std::cout << MAGENTA << "=== Test 1: Create valid forms ===" << RESET << std::endl;
	try {
		Form tax("Tax Form", 50, 25);
		Form contract("Contract", 10, 5);
		std::cout << tax << std::endl;
		std::cout << contract << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << MAGENTA << "\n=== Test 2: Invalid form grades ===" << RESET << std::endl;
	try {
		Form invalid("Invalid", 0, 50);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << MAGENTA << "\n=== Test 3: Bureaucrat signs form ===" << RESET << std::endl;
	try {
		Bureaucrat alice("Alice", 30);
		Form report("Report", 40, 20);
		std::cout << report << std::endl;
		alice.signForm(report);
		std::cout << report << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << MAGENTA << "\n=== Test 4: Grade too low to sign ===" << RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 100);
		Form vip("VIP Document", 10, 5);
		std::cout << vip << std::endl;
		bob.signForm(vip);
		std::cout << vip << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
