/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:20:19 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/18 11:03:20 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

// For rdm
#include <cstdlib>
#include <ctime>

// ============================================================================
// Handlers

// Destructor
Base::~Base() {}

// =============================================================================
// External

Base * generate(void) {

	// Init gen
	static bool seeded = false;

	if ( !seeded ) {

		std::srand(std::time(NULL));
		seeded = true;
	}

	// Random number [0 - 2]
	int rdm = std::rand() % 3;

	Base *ret = NULL;

	if ( rdm == 0 )
		ret = new A();

	else if (rdm == 1 )
		ret = new B();

	else
		ret = new C();

	return ret;
}

void identify(Base* p) {

	if ( dynamic_cast<A*>(p) )
		std::cout << "A type.\n";

	else if ( dynamic_cast<B*>(p) )
		std::cout << "B type.\n";

	else if ( dynamic_cast<C*>(p) )
		std::cout << "C type.\n";

	else
		std::cout << "WTF is this.\n";
}

void identify(Base& p) {

	A *a_ptr = dynamic_cast<A*>(&p);

	if ( a_ptr ) {

		std::cout << "A type.\n";
		return ;
	}

	B *b_ptr = dynamic_cast<B*>(&p);

	if ( b_ptr ) {

		std::cout << "B type.\n";
		return ;
	}

	C *c_ptr = dynamic_cast<C*>(&p);

	if ( c_ptr ) {

		std::cout << "C type.\n";
		return ;
	}

	std::cout << "WTF is this.\n";
}
