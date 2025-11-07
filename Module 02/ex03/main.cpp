/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:17:02 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/01 15:17:03 by gdosch           ###   ########.fr       */
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
	std::cout << "inside:  " << bsp(a, b, c, inside) << '\n';   // attendu: true
	std::cout << "outside: " << bsp(a, b, c, outside) << '\n';  // attendu: false
	std::cout << "vertex:  " << bsp(a, b, c, vertex) << '\n';   // attendu: false (sur un sommet)
	std::cout << "edge:    " << bsp(a, b, c, edge) << '\n';     // attendu: false (sur un côté)
}
