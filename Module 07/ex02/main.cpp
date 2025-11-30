/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:35:30 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/30 13:51:39 by gdosch           ###   ########.fr       */
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
		Array<int> empty;
		std::cout << "Size: " << empty.size() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << MAGENTA "\n=== TEST 2: INTEGER ARRAY ===" RESET << std::endl;
	try {
		Array<int> intArray(5);
		std::cout << "Size: " << intArray.size() << std::endl;
		for (unsigned int i = 0; i < intArray.size(); i++)
			intArray[i] = 9 - i;
		std::cout << "Values: ";
		for (unsigned int i = 0; i < intArray.size(); i++)
			std::cout << intArray[i] << " ";
		std::cout << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << MAGENTA "\n=== TEST 3: COPY CONSTRUCTOR ===" RESET << std::endl;
	try {
		Array<int> original(3);
		original[0] = 1;
		original[1] = 2;
		original[2] = 3;
		Array<int> copy(original);
		for (unsigned int i = 0; i < copy.size(); i++)
			copy[i]++;
		std::cout << "Original: " << original[0] << " " << original[1] << " " << original[2] << std::endl;
		std::cout << "Copy: " << copy[0] << " " << copy[1] << " " << copy[2] << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << MAGENTA "\n=== TEST 4: ASSIGNMENT OPERATOR ===" RESET << std::endl;
	try {
		Array<int> a(3);
		a[0] = 8;
		a[1] = 6;
		a[2] = 4;
		Array<int> b;
		b = a;
		for (unsigned int i = 0; i < b.size(); i++)
			b[i] /= 2;
		std::cout << "A: " << a[0] << " " << a[1] << " " << a[2] << std::endl;
		std::cout << "B: " << b[0] << " " << b[1] << " " << b[2] << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << MAGENTA "\n=== TEST 5: STRING ARRAY ===" RESET << std::endl;
	try {
		Array<std::string> strArray(3);
		strArray[0] = "Hello";
		strArray[1] = "World";
		strArray[2] = "!";
		std::cout << "String Array: ";
		for (unsigned int i = 0; i < strArray.size(); i++)
			std::cout << strArray[i] << " ";
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
}
