/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:54:22 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/17 14:10:30 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"
#include "AMateria.hpp"
#include <iostream>

Floor& Floor::getInstance() {
	static Floor instance;
	return instance;
}

Floor::Floor() : _count(0) {
	for (int i = 0; i < MAX_ITEMS; ++i)
		_items[i] = NULL;
}

Floor::~Floor() {
	for (int i = 0; i < _count; ++i) {
		delete _items[i];
		_items[i] = NULL;
	}
	_count = 0;
}

void Floor::add(AMateria* m) {
	if (!m)
		return;
	if (_count >= MAX_ITEMS) {
		std::cout << "Floor is full, deleting materia to avoid leak" << std::endl;
		delete m;
		return;
	}
	_items[_count++] = m;
	std::cout << "Dropped '" << m->getType() << "' materia on the floor" << std::endl;
}
