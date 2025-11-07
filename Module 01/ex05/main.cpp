/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:38:14 by gdosch            #+#    #+#             */
/*   Updated: 2025/10/28 18:38:15 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(void) {
	Harl	harl;
	
	std::cout << std::endl << "=== Testing all complaint levels ===" << std::endl;
	std::cout << std::endl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	std::cout << std::endl << "=== Testing invalid level ===" << std::endl;
	std::cout << std::endl;
	harl.complain("UNKNOWN");
	harl.complain("ANYTHING");
	harl.complain("");
	std::cout << std::endl << "=== Testing multiple complaints ===" << std::endl;
	std::cout << std::endl;
	harl.complain("ERROR");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("DEBUG");
}
