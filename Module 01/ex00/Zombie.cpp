/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:22:57 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/29 13:23:00 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <ctime>

// Constructor
Zombie::Zombie(const std::string &name) : _name(name) {
	announce();
}

// Destructor
Zombie::~Zombie(void) {
	static const char *deathMsgs[] = {
		" was chopped up with a chainsaw.",
		" was disintegrated by a rocket launcher.",
		" got its head blown off with a shotgun.",
		" was set on fire with a Molotov cocktail.",
		" was crushed under a tank.",
		" was electrocuted by a power surge.",
		" got sliced in half by a katana.",
		" was smashed by a baseball bat.",
		" was run over by a truck.",
		" stepped on a mine and exploded into pieces!",
		" was incinerated by a flamethrower."
	};
	static const int count = sizeof(deathMsgs) / sizeof(*deathMsgs);

	std::cout << this->_name << deathMsgs[clock() % count] << std::endl;
}

// Core method(s)
void Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
