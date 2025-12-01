/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:46:35 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/20 14:07:10 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>


int main( void ) {

	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	// or with tab
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vec2(arr, arr + 5);

	try {

		// 1
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found: " << *it << " at index: " << it - vec.begin() << std::endl;

		// 2
		std::vector<int>::iterator it2 = easyfind(vec2, 5);
		std::cout << "Found: " << *it2 << " at index: " << it2 - vec2.begin() << std::endl;
	}

	catch ( const std::exception &e ) {

		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
