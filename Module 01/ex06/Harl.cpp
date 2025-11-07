/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:38:01 by gdosch            #+#    #+#             */
/*   Updated: 2025/10/28 18:38:03 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

// Constructor
Harl::Harl() {}

// Destructor
Harl::~Harl() {}

#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define MAGENTA "\033[35m"
#define CYAN	"\033[36m"
#define RESET	"\033[0m"

// Core method(s)
void Harl::debug(void) {
	std::cout << CYAN << "[ DEBUG ]" << RESET << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info(void) {
	std::cout << GREEN << "[ INFO ]" << RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void) {
	std::cout << YELLOW << "[ WARNING ]" << RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error(void) {
	std::cout << RED << "[ ERROR ]" << RESET << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Harl::complain(std::string level) {
	const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int levelIndex = -1;
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			levelIndex = i;
			break;
		}
	}
	switch (levelIndex) {
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "[ " << MAGENTA << "Probably complaining about insignificant problems" << RESET << " ]" << std::endl;
			std::cout << std::endl;
	}
}
