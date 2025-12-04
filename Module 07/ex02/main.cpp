/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:35:30 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/04 11:47:42 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

int main(void) {
	std::cout << MAGENTA "=== TEST 1: EMPTY ARRAY ===" RESET << std::endl;
	try {
		Array<int> empty1;
		std::cout << "[ Default constructor ]\nsize = " << empty1.size() << std::endl;
		Array<int> empty2(0);
		std::cout << "[ Parameterized constructor ]\nsize = " << empty2.size() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << MAGENTA "\n=== TEST 2: INTEGER ARRAY ===" RESET << std::endl;
	try {
		Array<int> intArray(4);
		std::cout << "Size:\t\t" << intArray.size() << std::endl;
		std::cout << "Initialized:\t";
		for (unsigned int i = 0; i < intArray.size(); i++)
			std::cout << intArray[i] << " ";
		std::cout << std::endl;
		for (unsigned int i = 0; i < intArray.size(); i++)
			intArray[i] = 9 - i;
		std::cout << "Assignated:\t";
		for (unsigned int i = 0; i < intArray.size(); i++)
			std::cout << intArray[i] << " ";
		std::cout << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << MAGENTA "\n=== TEST 3: COPY CONSTRUCTOR ===" RESET << std::endl;
	try {
		Array<int> original(4);
		for (unsigned int i = 0; i < original.size(); i++)
			original[i] = i + 1;
		Array<int> copy(original);
		for (unsigned int i = 0; i < copy.size(); i++)
			copy[i]++;
		std::cout << "Original:\t";
		for (unsigned int i = 0; i < original.size(); i++)
			std::cout << original[i] << " ";
		std::cout << std::endl;
		std::cout << "Plus one copy:\t";
		for (unsigned int i = 0; i < copy.size(); i++)
			std::cout << copy[i] << " ";
		std::cout << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << MAGENTA "\n=== TEST 4: ASSIGNMENT OPERATOR ===" RESET << std::endl;
	try {
		Array<int> original(4);
		for (unsigned int i = 0; i < original.size(); i++)
			original[i] = 8 - (2 * i);
		Array<int> copy;
		copy = original;
		for (unsigned int i = 0; i < copy.size(); i++)
			copy[i] /= 2;
		std::cout << "Original:\t";
		for (unsigned int i = 0; i < original.size(); i++)
			std::cout << original[i] << " ";
		std::cout << std::endl;
		std::cout << "Halved copy:\t";
		for (unsigned int i = 0; i < copy.size(); i++)
			std::cout << copy[i] << " ";
		std::cout << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << MAGENTA "\n=== TEST 5: STRING ARRAY ===" RESET << std::endl;
	try {
		Array<std::string> strArray(3);
		strArray[0] = "Hello";
		strArray[1] = "World";
		strArray[2] = "!";
		std::cout << "Elements:\t";
		for (unsigned int i = 0; i < strArray.size(); i++)
			std::cout << "'" << strArray[i] << "' ";
		std::cout << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n" MAGENTA "=== TEST 6: OUT OF BOUNDS EXCEPTION ===" RESET << std::endl;
	try {
		Array<int> intArray(5);
		std::cout << intArray[5] << std::endl;
		std::cout << "[ FAILURE: Should have thrown exception ]" RESET << std::endl;

	} catch (const std::exception& e) {
		std::cout << "[ SUCCESS ] Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n" MAGENTA "=== TEST 7: INTEGER CONST ARRAY ===" RESET << std::endl;
	try {
		Array<int> constIntArray(4);
		for (unsigned int i = 0; i < constIntArray.size(); i++)
			constIntArray[i] = i + 5;
		const Array<int> constArray(constIntArray);
		std::cout << "Size:\t\t" << constArray.size() << std::endl;
		std::cout << "Values:\t\t";
		for (unsigned int i = 0; i < constArray.size(); i++)
			std::cout << constArray[i] << " ";
		std::cout << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n" MAGENTA "=== TEST 8: CONST ARRAY OUT OF BOUNDS ===" RESET << std::endl;
	try {
		Array<int> temp(3);
		const Array<int> constArray(temp);
		std::cout << constArray[3] << std::endl;
		std::cout << "[ FAILURE: Should have thrown exception ]" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "[ SUCCESS ] Exception caught: " << e.what() << std::endl;
	}
}
