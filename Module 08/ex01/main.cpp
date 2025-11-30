/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:26:01 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/30 18:53:32 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

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
		std::cout << sp.shortestSpan() << std::endl;  // Expected: 2 (between 9 and 11)
		std::cout << sp.longestSpan() << std::endl;   // Expected: 14 (17 - 3)
	}

	std::cout << MAGENTA "\n=== TEST 2: FULL CONTAINER ===" RESET << std::endl;
	{
		try {
			Span sp = Span(3);
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4); // Should throw exception
		} catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	std::cout << MAGENTA "\n=== TEST 3: NOT ENOUGH NUMBERS ===" RESET << std::endl;
	{
		try {
			Span sp = Span(5);
			sp.addNumber(1);
			std::cout << sp.shortestSpan() << std::endl; // Should throw exception
		} catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	std::cout << MAGENTA "\n=== TEST 4: 10,000 NUMBERS ===" RESET << std::endl;
	{
		Span sp = Span(10000);
		for (int i = 0; i < 10000; ++i)
			sp.addNumber(i * 2);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Expected: 2
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Expected: 19998
	}

	std::cout << MAGENTA "\n=== TEST 5: ITERATOR RANGE ===" RESET << std::endl;
	{
		Span sp = Span(10000);
		std::vector<int> vec;
		for (int i = 0; i < 10000; ++i) {
			vec.push_back(i * 3);
		}
		sp.addRange(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Expected: 3
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Expected: 29997
	}

	std::cout << MAGENTA "\n=== TEST 6: NEGATIVE NUMBERS ===" RESET << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(-10);
		sp.addNumber(-5);
		sp.addNumber(0);
		sp.addNumber(5);
		sp.addNumber(10);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Expected: 5
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Expected: 20
	}
}
