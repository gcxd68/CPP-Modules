/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:22:26 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/21 10:08:59 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main( void ) {

	//==========================================================================
	// SMALL SPAN TEST =========================================================

	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(69);
	sp.addNumber(11);

	std::cout << "\nSMALL SPAN ===========================================\n\n";

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	//==========================================================================
	// BIG SPAN TEST ===========================================================

	// Create big Span
	Span bigSpan(1000);

	// Create vector with lot of new numbers
	std::vector<int> lotsNumbers;

	for ( int i = 0; i < 500; i++ )
		lotsNumbers.push_back(i);

	// Add the vector to the big Span
	bigSpan.addNumber(lotsNumbers.begin(), lotsNumbers.end());

	std::cout << "\nBIG SPAN =============================================\n\n";

	std::cout << bigSpan.shortestSpan() << std::endl;
	std::cout << bigSpan.longestSpan() << std::endl;


	//==========================================================================
	// EXCEPTION TEST ==========================================================

	std::cout << "\nEXCEPTION ============================================\n\n";

	// FULL
	try {

		sp.addNumber(42);
	}

	catch ( const std::exception &e ) {

		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// EMPTY
	Span empty(5);

	try {

		empty.shortestSpan();
	}

	catch ( const std::exception &e ) {

		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}
