/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:46:43 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/18 11:07:53 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.h"
#include "Serializer.hpp"

#include <iostream>

int main( void ) {

	Data origine;

	origine.value = 42;
	origine.name = "Mulhouse";
	origine.price = 42.42;

	Data *originePtr = &origine;

	// Serialize
	uintptr_t serialized = Serializer::serialize(originePtr);

	// Deserialize
	Data *deserializedPtr = Serializer::deserialize(serialized);

	// Output
	std::cout << "Original ptr:\t" << originePtr << std::endl;
	std::cout << "Serialized:\t" << serialized << std::endl;
	std::cout << "Deserialized:\t" << deserializedPtr << std::endl;

	// Test
	if ( originePtr == deserializedPtr )
		std::cout << "\nPtr are equal.\n\n";
	else
		std::cout << "\nPtr are different.\n\n";

	std::cout << "Origine Data:\t\t" << originePtr->value << ", " << originePtr->name << ", " << originePtr->price << std::endl;
	std::cout << "Deserialized Data:\t" << deserializedPtr->value << ", " << deserializedPtr->name << ", " << deserializedPtr->price << std::endl;
}
