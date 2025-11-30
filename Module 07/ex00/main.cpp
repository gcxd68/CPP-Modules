/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:35:30 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/30 12:08:00 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

int main(void)
{
	std::cout << MAGENTA << "=== TEST 1: SIGNED INTEGERS ===" << RESET << std::endl;
	int a = -3, b = 2;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::cout << MAGENTA << "\n=== TEST 2: UNSIGNED INTEGERS ===" << RESET << std::endl;
	unsigned int c = 42, d = 24;
	std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	std::cout << MAGENTA << "\n=== TEST 3: STRINGS ===" << RESET << std::endl;
	std::string e = "string1", f = "string2";
	std::cout << "Before swap: e = '" << e << "', f = '" << f << "'" << std::endl;
	::swap(e, f);
	std::cout << "After swap: e = '" << e << "', f = '" << f << "'" << std::endl;
	std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
	std::cout << "max(e, f) = " << ::max(e, f) << std::endl;
}
