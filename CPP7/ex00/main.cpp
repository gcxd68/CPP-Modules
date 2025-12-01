/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:46:35 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/19 09:26:30 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Operation.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	Operation::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << Operation::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << Operation::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	Operation::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << Operation::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << Operation::max( c, d ) << std::endl;
	return 0;
}
