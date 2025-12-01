/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:54:40 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/01 12:32:20 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

int main() {
	std::cout << MAGENTA "=== TEST 1: std::vector ===" RESET << std::endl;
	std::vector<int> vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(4);
	vec1.push_back(5);
	std::cout << "vec1 values:\t";
	for (std::vector<int>::iterator it = vec1.begin(); it != vec1.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	int arr1[] = {9, 8, 7, 6, 5};
	std::vector<int> vec2(arr1, arr1 + 5);
	std::cout << "vec2 values:\t";
	for (std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	try {
		std::cout << "Finding 3 in vec1: " << *easyfind(vec1, 3) << std::endl;
		std::cout << "Finding 6 in vec2: " << *easyfind(vec2, 6) << std::endl;
		std::cout << "Finding 0 in vec2: " << *easyfind(vec2, 0) << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << MAGENTA "\n=== TEST 2: std::list ===" RESET << std::endl;
	std::list<int> lst1;
	lst1.push_back(10);
	lst1.push_back(20);
	lst1.push_back(30);
	std::cout << "lst1 values:\t";
	for (std::list<int>::iterator it = lst1.begin(); it != lst1.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	int arr2[] = {90, 80, 70};
	std::list<int> lst2(arr2, arr2 + 3);
	std::cout << "lst2 values:\t";
	for (std::list<int>::iterator it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	try {
		std::cout << "Finding 20 in lst1: " << *easyfind(lst1, 20) << std::endl;
		std::cout << "Finding 70 in lst2: " << *easyfind(lst2, 70) << std::endl;
		std::cout << "Finding 10 in lst2: " << *easyfind(lst2, 10) << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
