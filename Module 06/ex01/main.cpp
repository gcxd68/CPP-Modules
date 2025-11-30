/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:37:01 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/30 15:29:23 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

int main() {
	std::cout << MAGENTA << "==== SERIALIZATION TEST ====" << RESET << std::endl;
	Data originalData;
	originalData.id = 42;
	originalData.name = "Test Data";
	originalData.value = 3.14f;

	std::cout << "Original Data:" << std::endl;
	std::cout << "\tAddress: " << &originalData << std::endl;
	std::cout << "\tID: " << originalData.id << std::endl;
	std::cout << "\tName: " << originalData.name << std::endl;
	std::cout << "\tValue: " << originalData.value << std::endl;
	std::cout << std::endl;

	uintptr_t serialized = Serializer::serialize(&originalData);
	std::cout << "Serialized:" << std::endl;
	std::cout << "\t0x" << std::hex << serialized << std::dec << std::endl;
	std::cout << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "\tAddress: " << deserialized << std::endl;
	std::cout << "\tID: " << deserialized->id << std::endl;
	std::cout << "\tName: " << deserialized->name << std::endl;
	std::cout << "\tValue: " << deserialized->value << std::endl;
	std::cout << std::endl;

	if (deserialized == &originalData)
		std::cout << "[ SUCCESS : pointers are equal ]" << std::endl;
	else
		std::cout << "[ FAILURE : pointers are different ]" << std::endl;
}
