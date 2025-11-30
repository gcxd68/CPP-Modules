/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:35:30 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/30 12:13:52 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

template <typename T>
void print(const T& element) {
	std::cout << element << " ";
}

template <typename T>
void addOne(T& element) {
	element += 1;
}

template <typename T>
void doubleValue(T& element) {
	element *= 2;
}

template <typename T>
void toMockingCase(T& element) {
	for (size_t i = 0; i < element.length(); i++) {
		if (i % 2)
			element[i] = std::toupper(element[i]);
		else
			element[i] = std::tolower(element[i]);			
	}
}

int main(void) {
	std::cout << MAGENTA << "=== TEST 1: ARRAY OF INTEGERS ===" << RESET << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intSize = sizeof(intArray) / sizeof(*intArray);
	std::cout << "Original:\t";
	::iter(intArray, intSize, print<int>);
	std::cout << std::endl;
	::iter(intArray, intSize, addOne<int>);
	std::cout << "After adding 1:\t";
	::iter(intArray, intSize, print<int>);
	std::cout << std::endl;
	::iter(intArray, intSize, doubleValue<int>);
	std::cout << "After double:\t";
	::iter(intArray, intSize, print<int>);
	std::cout << std::endl;

	std::cout << MAGENTA << "\n=== TEST 2: ARRAY OF FLOATS ===" << RESET << std::endl;
	float floatArray[] = {1.1f, 2.2f, 3.3f};
	size_t floatSize = sizeof(floatArray) / sizeof(*floatArray);
	std::cout << "Original:\t";
	::iter(floatArray, floatSize, print<float>);
	std::cout << std::endl;
	::iter(floatArray, floatSize, addOne<float>);
	std::cout << "After adding 1:\t";
	::iter(floatArray, floatSize, print<float>);
	std::cout << std::endl;

	::iter(floatArray, floatSize, doubleValue<float>);
	std::cout << "After double:\t";
	::iter(floatArray, floatSize, print<float>);
	std::cout << std::endl;

	std::cout << MAGENTA << "\n=== TEST 3: ARRAY OF STRINGS ===" << RESET << std::endl;
	std::string strArray[] = {"Hello", "World", "42"};
	size_t strSize = sizeof(strArray) / sizeof(*strArray);
	std::cout << "Original:\t";
	::iter(strArray, strSize, print<std::string>);
	std::cout << std::endl;
	::iter(strArray, strSize, toMockingCase<std::string>);
	std::cout << "Mocking case:\t";
	::iter(strArray, strSize, print<std::string>);
	std::cout << std::endl;

	std::cout << MAGENTA << "\n=== TEST 4: CONST ARRAY OF INTEGERS ===" << RESET << std::endl;
	const int constIntArray[] = {5, 4, 3, 2, 1};
	size_t constIntSize = sizeof(constIntArray) / sizeof(*constIntArray);
	std::cout << "Const array:\t";
	::iter(constIntArray, constIntSize, print<int>);
	std::cout << std::endl;
	// ::iter(constIntArray, constIntSize, addOne<int>);  // Error: cannot modify const

	std::cout << MAGENTA << "\n=== TEST 5: CONST ARRAY OF FLOATS ===" << RESET << std::endl;
	const float constFloatArray[] = {3.3f, 2.2f, 1.1f};
	size_t constFloatSize = sizeof(constFloatArray) / sizeof(*constFloatArray);
	std::cout << "Const floats:\t";
	::iter(constFloatArray, constFloatSize, print<float>);
	std::cout << std::endl;
	// ::iter(constFloatArray, constFloatSize, doubleValue<float>);  // Error: cannot modify const

	std::cout << MAGENTA << "\n=== TEST 6: CONST ARRAY OF STRINGS ===" << RESET << std::endl;
	const std::string constStrArray[] = {"read", "only", "array"};
	size_t constStrSize = sizeof(constStrArray) / sizeof(*constStrArray);
	std::cout << "Const strings:\t";
	::iter(constStrArray, constStrSize, print<std::string>);
	std::cout << std::endl;
	// ::iter(constStrArray, constStrSize, toUpperCase<std::string>);  // Error: cannot modify const

}
