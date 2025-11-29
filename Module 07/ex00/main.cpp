/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:35:30 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/29 21:59:09 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

int main(void)
{
	std::cout << MAGENTA << "=== TEST 1: INTEGERS ===" << RESET << std::endl;
	int a = 2, b = 3;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::cout << MAGENTA << "\n=== TEST 2: STRINGS ===" << RESET << std::endl;
	std::string c = "string1", d = "string2";
	std::cout << "Before swap: c = '" << c << "', d = '" << d << "'" << std::endl;
	::swap(c, d);
	std::cout << "After swap: c = '" << c << "', d = '" << d << "'" << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
}
