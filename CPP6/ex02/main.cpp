/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:20:09 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/18 10:57:37 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main () {

	// Alea gen
	for ( int i = 0; i < 10; i++ ) {

		Base *obj = generate();
		std::cout << "\n===== " << i + 1 << " =====\n";
		std::cout << "PTR: ";
		identify(obj);
		std::cout << "Ref: ";
		identify(*obj);
		delete obj;
	}
}
