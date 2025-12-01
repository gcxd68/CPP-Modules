/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:27:00 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/21 10:45:37 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main() {


	// Classic Stack
	MutantStack<int> aled;

	aled.push(5);
	aled.push(17);

	std::cout << "\nOn top of stack ========================================\n";
	std::cout << aled.top() << std::endl;

	aled.pop();

	std::cout << "\nSize after pop() =======================================\n";
	std::cout << aled.size() << std::endl;

	aled.push(3);
	aled.push(5);
	aled.push(737);
	aled.push(0);

	// Iterator inside a Stack OMFG
	MutantStack<int>::iterator it  = aled.begin();
	MutantStack<int>::iterator ite = aled.end();

	std::cout << "\nIterator on a Stack OMFG ===============================\n";

	while ( it != ite ) {

		std::cout << *it << std::endl;
		it++;
	}

	std::cout << "\n========================================================\n";
}
