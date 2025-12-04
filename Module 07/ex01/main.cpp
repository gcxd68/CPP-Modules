/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:35:30 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/04 10:19:28 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>
#include <cctype>

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
void addOne(const T&) {}

template <typename T>
void doubleValue(T& element) {
	element *= 2;
}

template <typename T>
void doubleValue(const T&) {}


template <typename T>
void toMockingCase(T& string) {
	for (size_t i = 0; i < string.length(); i++)
		string[i] = i % 2 ? std::toupper(string[i]) : std::tolower(string[i]);
}

template <typename T>
void toMockingCase(const T&) {}

int main(void) {
	std::cout << MAGENTA << "=== TEST 1: INTEGER ARRAY ===" << RESET << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intSize = sizeof(intArray) / sizeof(*intArray);
	std::cout << "Original:\t";
	::iter(intArray, intSize, print);
	std::cout << std::endl;
	::iter(intArray, intSize, addOne);
	std::cout << "After adding 1:\t";
	::iter(intArray, intSize, print);
	std::cout << std::endl;
	::iter(intArray, intSize, doubleValue);
	std::cout << "After double:\t";
	::iter(intArray, intSize, print);
	std::cout << std::endl;

	std::cout << MAGENTA << "\n=== TEST 2: FLOAT ARRAY ===" << RESET << std::endl;
	float floatArray[] = {1.1f, 2.2f, 3.3f};
	size_t floatSize = sizeof(floatArray) / sizeof(*floatArray);
	std::cout << "Original:\t";
	::iter(floatArray, floatSize, print);
	std::cout << std::endl;
	::iter(floatArray, floatSize, addOne);
	std::cout << "After adding 1:\t";
	::iter(floatArray, floatSize, print);
	std::cout << std::endl;
	::iter(floatArray, floatSize, doubleValue);
	std::cout << "After double:\t";
	::iter(floatArray, floatSize, print);
	std::cout << std::endl;

	std::cout << MAGENTA << "\n=== TEST 3: STRING ARRAY ===" << RESET << std::endl;
	std::string strArray[] = {"Hello", "World", "42"};
	size_t strSize = sizeof(strArray) / sizeof(*strArray);
	std::cout << "Original:\t";
	::iter(strArray, strSize, print);
	std::cout << std::endl;
	::iter(strArray, strSize, toMockingCase);
	std::cout << "Mocking case:\t";
	::iter(strArray, strSize, print);
	std::cout << std::endl;

	std::cout << MAGENTA << "\n=== TEST 4: CONST INTEGER ARRAY ===" << RESET << std::endl;
	const int constIntArray[] = {5, 4, 3, 2, 1};
	size_t constIntSize = sizeof(constIntArray) / sizeof(*constIntArray);
	std::cout << "Original:\t";
	::iter(constIntArray, constIntSize, print);
	std::cout << std::endl;
	std::cout << "After adding 1:\t";
	::iter(constIntArray, constIntSize, addOne);
	::iter(constIntArray, constIntSize, print);
	std::cout << std::endl;

	std::cout << MAGENTA << "\n=== TEST 5: CONST FLOAT ARRAY ===" << RESET << std::endl;
	const float constFloatArray[] = {3.3f, 2.2f, 1.1f};
	size_t constFloatSize = sizeof(constFloatArray) / sizeof(*constFloatArray);
	std::cout << "Original:\t";
	::iter(constFloatArray, constFloatSize, print);
	std::cout << std::endl;
	std::cout << "After double:\t";
	::iter(constFloatArray, constFloatSize, doubleValue);
	::iter(constFloatArray, constFloatSize, print);
	std::cout << std::endl;

	std::cout << MAGENTA << "\n=== TEST 6: CONST STRING ARRAY ===" << RESET << std::endl;
	const std::string constStrArray[] = {"read", "only", "array"};
	size_t constStrSize = sizeof(constStrArray) / sizeof(*constStrArray);
	std::cout << "Original:\t";
	::iter(constStrArray, constStrSize, print);
	std::cout << std::endl;
	std::cout << "Mocking case:\t";
	::iter(constStrArray, constStrSize, toMockingCase);
	::iter(constStrArray, constStrSize, print);
	std::cout << std::endl;
}
