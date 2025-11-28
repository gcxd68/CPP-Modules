/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:16:35 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/28 14:56:56 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Destructor
Base::~Base() {}

// Free function(s)
Base* generate(void) {
	static bool seeded = false;
	if (!seeded) {
		std::srand(std::time(NULL));
		seeded = true;
	}
	int random_choice = std::rand() % 3;
	if (random_choice == 0)
		return new A();
	if (random_choice == 1)
		return new B();
	return new C();
}

void identify(Base* p) {
	std::cout << "[Pointer] Actual type: ";
	if (!p) {
		std::cout << "NULL" << std::endl;
		return;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "Unknown";
	std::cout << std::endl;
}

void identify(Base& p) {
	std::cout << "[Reference] Actual type: ";
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (...) {}
	std::cout << "Unknown" << std::endl;
}
