/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:17:02 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/01 15:17:03 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {
	Fixed a;
	a.setRawBits(2);	// a = 2
	Fixed b(a);			// b = 2
	a.setRawBits(1);	// a = 1
	b.setRawBits(3);	// b = 3
	Fixed c;
	c = b;				// c = 3
	b.setRawBits(2);	// b = 2

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}
