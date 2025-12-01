/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:26:01 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/01 15:31:14 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <limits>
#include <vector>

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

int main() {
	std::cout << MAGENTA "=== TEST 1: 42 ===" RESET << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Values: ";
		for (size_t i = 0; i < sp.size(); i++)
			std::cout << sp[i] << " ";
		std::cout << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << MAGENTA "\n=== TEST 2: ADDRANGE + NEGATIVE INTEGERS ===" RESET << std::endl;
	{
		Span sp = Span(4);
		std::vector<int> vec;
		vec.push_back(-57);
		vec.push_back(-2);
		vec.push_back(10);
		vec.push_back(50);
		vec.push_back(-5);
		vec.push_back(199);
		std::cout << "src values: ";
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << " ";
		sp.addRange(vec.begin() + 2, vec.end() - 1);
		std::cout << std::endl;
		std::cout << "After addRange: ";
		for (size_t i = 0; i < sp.size(); i++)
			std::cout << sp[i] << " ";
		std::cout << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << MAGENTA "\n=== TEST 3: MAX SPAN ===" RESET << std::endl;
	{
		Span sp = Span(2);
		sp.addNumber(std::numeric_limits<int>::min()); // INT_MIN = -2147483648
		sp.addNumber(std::numeric_limits<int>::max()); // INT_MAX = 2147483647
		std::cout << "Values: ";
		for (size_t i = 0; i < sp.size(); i++)
			std::cout << sp[i] << " ";
		std::cout << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Expected: UINT_MAX = 4294967295
		std::cout << "Longest span: " << sp.longestSpan() << std::endl; // Expected: UINT_MAX = 4294967295
	}

	std::cout << MAGENTA "\n=== TEST 5: FULL CONTAINER ===" RESET << std::endl;
	{
		try {
			Span sp = Span(3);
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4);
		} catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << MAGENTA "\n=== TEST 6: NOT ENOUGH NUMBERS ===" RESET << std::endl;
	{
		try {
			Span sp = Span(5);
			sp.addNumber(1);
			std::cout << sp.shortestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
}
