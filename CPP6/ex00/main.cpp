/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:46:35 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/17 15:03:11 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main ( int ac, char **av ) {

	if ( ac != 2) {
		
		std::cout << "Usage " << av[0] << " <input>\n";
		return 1;
	}


	ScalarConverter::convert(av[1]);
}
