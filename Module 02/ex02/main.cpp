/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:17:02 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/10 15:32:22 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {
	Fixed	a;
	Fixed	const b(Fixed(5.05f) * Fixed(2));

	std::cout << "\n=== 42 TEST ===" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << std::endl << "=== CONSTRUCTION CHAIN ===" << std::endl;
	Fixed c;
	Fixed d(10);
	Fixed e(42.42f);
	Fixed f;
	f = d;
	
	std::cout << std::endl << "=== VALUES ===" << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl;

	std::cout << std::endl << "=== COMPARISON OPERATORS ===" << std::endl;
	std::cout << std::boolalpha;
	std::cout << "d > c: " << (d > c) << std::endl;
	std::cout << "d <= f: " << (d <= f) << std::endl;
	std::cout << "d == f: " << (d == f) << std::endl;
	std::cout << "d != c: " << (d != c) << std::endl;

	std::cout << std::endl << "=== ARITHMETIC OPERATORS ===" << std::endl;
	std::cout << "d + e = " << std::endl << (d + e) << std::endl;
	std::cout << "e - d = " << std::endl << (e - d) << std::endl;
	std::cout << "d * e = " << std::endl << (d * e) << std::endl;
	std::cout << "e / d = " << std::endl << (e / d) << std::endl;

	std::cout << std::endl << "=== INCREMENT/DECREMENT OPERATORS ===" << std::endl;
	Fixed g(5);
	std::cout << "g = " << g << std::endl;
	std::cout << "++g = " << ++g << std::endl;
	std::cout << "g = " << g << std::endl;
	std::cout << "g++ = " << std::endl << g++ << std::endl;
	std::cout << "g = " << g << std::endl;
	std::cout << "--g = " << --g << std::endl;
	std::cout << "g = " << g << std::endl;
	std::cout << "g-- = " << std::endl << g-- << std::endl;
	std::cout << "g = " << g << std::endl;

	std::cout << std::endl << "=== STATIC FUNCTIONS (min/max) ===" << std::endl;
	std::cout << "min(d, e) = " << Fixed::min(d, e) << std::endl;
	std::cout << "max(d, e) = " << Fixed::max(d, e) << std::endl;

	Fixed const h(15.5f);
	Fixed const i(20.2f);
	std::cout << "min(h, i) [const] = " << Fixed::min(h, i) << std::endl;
	std::cout << "max(h, i) [const] = " << Fixed::max(h, i) << std::endl;

	std::cout << std::endl << "=== CONVERSION FUNCTIONS ===" << std::endl;
	std::cout << "e.toInt() = " << e.toInt() << std::endl;
	std::cout << "e.toFloat() = " << e.toFloat() << std::endl;

	std::cout << std::endl << "=== DESTRUCTION CHAIN ===" << std::endl;
}
