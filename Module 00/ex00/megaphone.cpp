/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:08:41 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/20 18:08:41 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main( int argc, char **argv ) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < argc; i++)
			for (size_t j = 0; argv[i][j]; j++)
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
	std::cout << std::endl;
}
