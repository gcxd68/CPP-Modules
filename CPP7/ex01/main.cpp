/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:45:47 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/19 10:12:50 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

void print_intx2(int &x) { std::cout << x * 2 << " "; }
void print_int(const int &x) { std::cout << x << " "; }
void print_string(std::string &s) { std::cout << "Hello_" + s << " "; }
void print_char(char &c) { std::cout << (char)std::toupper(c) << " "; }

int main() {

	int tab[] = {1, 2, 3, 4, 5};
	std::string stab[] = {"aa", "bb", "cc"};
	char ctab[] = {'a', 'b', 'c', 'd'};

	const int constTab[] = {0, 0, 0, 0};


	iter(tab, 5, print_intx2);
	std::cout << std::endl;

	iter(stab, 3, print_string);
	std::cout << std::endl;

	iter(ctab, 4, print_char);
	std::cout << std::endl;

	iter(constTab, 4, print_int);
	std::cout << std::endl;

}
