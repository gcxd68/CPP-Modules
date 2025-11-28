/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:36:59 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/28 13:00:42 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Unused special member functions
Serializer::Serializer(void) {}
Serializer::Serializer(const Serializer&) {}
Serializer& Serializer::operator=(const Serializer&) { return *this; }
Serializer::~Serializer(void) {}

// Core method(s)
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
