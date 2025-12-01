/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:47:35 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/18 11:07:45 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// ============================================================================
// Handlers

// Default Constructor
Serializer::Serializer() {}

// Copy Constructor
Serializer::Serializer( const Serializer &other ) {

	(void)other;
}

// Assignation operator
Serializer &Serializer::operator=(const Serializer &other) {

	(void)other;
	return *this;
}

// Destructor
Serializer::~Serializer() {}

// =============================================================================
// Methods

uintptr_t Serializer::serialize(Data *ptr) {

	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {

	return reinterpret_cast<Data*>(raw);
}
