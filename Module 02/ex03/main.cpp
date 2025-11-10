/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:17:02 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/10 15:33:22 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main() {
	Point a(0.f, 0.f);
	Point b(10.f, 0.f);
	Point c(0.f, 10.f);
	Point inside(1.f, 1.f);
	Point outside(10.f, 10.f);
	Point vertex(0.f, 0.f);
	Point edge(5.f, 0.f);
	std::cout << std::boolalpha;
	std::cout << "inside (1.0, 1.0):\t" << bsp(a, b, c, inside) << "\t(should be true)" << std::endl;
	std::cout << "outside: (10.0, 10.0):\t" << bsp(a, b, c, outside) << "\t(should be false)" << std::endl;
	std::cout << "vertex (0.0, 0.0):\t" << bsp(a, b, c, vertex) << "\t(should be false)" << std::endl;
	std::cout << "edge: (5.0, 0.0):\t" << bsp(a, b, c, edge) << "\t(should be false)" << std::endl;
}
