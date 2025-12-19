/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:18:31 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/19 10:40:08 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: usage: ./RPN \"reverse polish mathematical expression\"" << std::endl;
		return 2;
	}
	RPN calculator;
	try {
		std::cout << calculator.evaluate(argv[1]) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
