/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:13:20 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/19 14:26:22 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main() {

	int size  = 3;

	Array<int> arr(size);

	arr[0] = 42;
	arr[1] = 1;
	arr[2] = 4555;

	for ( int i = 0; i < size; i++ )
		std::cout << arr[i] << std::endl;

	std::cout << "Size: " << arr.size() << std::endl;

}
