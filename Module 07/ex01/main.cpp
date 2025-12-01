/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:35:30 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/01 10:47:44 by gdosch           ###   ########.fr       */
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
void toMockingCase(T& element) {
    for (size_t i = 0; i < element.length(); i++) {
        if (i % 2)
            element[i] = std::toupper(element[i]);
        else
            element[i] = std::tolower(element[i]);
    }
}

template <typename T>
void toMockingCase(const T&) {}

int main(void) {
    std::cout << MAGENTA << "=== TEST 1: INTEGER ARRAY ===" << RESET << std::endl;
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

    std::cout << MAGENTA << "\n=== TEST 2: FLOAT ARRAY ===" << RESET << std::endl;
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

    std::cout << MAGENTA << "\n=== TEST 3: STRING ARRAY ===" << RESET << std::endl;
    std::string strArray[] = {"Hello", "World", "42"};
    size_t strSize = sizeof(strArray) / sizeof(*strArray);
    std::cout << "Original:\t";
    ::iter(strArray, strSize, print<std::string>);
    std::cout << std::endl;
    ::iter(strArray, strSize, toMockingCase<std::string>);
    std::cout << "Mocking case:\t";
    ::iter(strArray, strSize, print<std::string>);
    std::cout << std::endl;

    std::cout << MAGENTA << "\n=== TEST 4: CONST INTEGER ARRAY ===" << RESET << std::endl;
    const int constIntArray[] = {5, 4, 3, 2, 1};
    size_t constIntSize = sizeof(constIntArray) / sizeof(*constIntArray);
    std::cout << "Original:\t";
    ::iter(constIntArray, constIntSize, print<int>);
    std::cout << std::endl;
    std::cout << "After adding 1:\t";
    ::iter(constIntArray, constIntSize, addOne<int>);
    ::iter(constIntArray, constIntSize, print<int>);
    std::cout << std::endl;

    std::cout << MAGENTA << "\n=== TEST 5: CONST FLOAT ARRAY ===" << RESET << std::endl;
    const float constFloatArray[] = {3.3f, 2.2f, 1.1f};
    size_t constFloatSize = sizeof(constFloatArray) / sizeof(*constFloatArray);
    std::cout << "Original:\t";
    ::iter(constFloatArray, constFloatSize, print<float>);
    std::cout << std::endl;
    std::cout << "After double:\t";
    ::iter(constFloatArray, constFloatSize, doubleValue<float>);
    ::iter(constFloatArray, constFloatSize, print<float>);
    std::cout << std::endl;

    std::cout << MAGENTA << "\n=== TEST 6: CONST STRING ARRAY ===" << RESET << std::endl;
    const std::string constStrArray[] = {"read", "only", "array"};
    size_t constStrSize = sizeof(constStrArray) / sizeof(*constStrArray);
    std::cout << "Original:\t";
    ::iter(constStrArray, constStrSize, print<std::string>);
    std::cout << std::endl;
    std::cout << "Mocking case:\t";
    ::iter(constStrArray, constStrSize, toMockingCase<std::string>);
    ::iter(constStrArray, constStrSize, print<std::string>);
    std::cout << std::endl;
}
