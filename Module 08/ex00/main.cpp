/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:54:40 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/30 18:53:20 by gdosch           ###   ########.fr       */
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
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	try {
		std::cout << "Finding 3 in vector: " << *easyfind(vec, 3) << std::endl;
		std::cout << "Finding 6 in vector: " << *easyfind(vec, 6) << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << MAGENTA "\n=== TEST 2: std::list ===" RESET << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	try {
		std::cout << "Finding 20 in list: " << *easyfind(lst, 20) << std::endl;
		std::cout << "Finding 99 in list: " << *easyfind(lst, 99) << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
