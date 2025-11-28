/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:19:30 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/28 14:56:13 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

int main() {
	for (int i = 0; i < 10; i++) {
		Base *obj = generate();
		std::cout
			<< (i ? "\n" : "") << MAGENTA
			<< "==== Base object No." << i + 1 << " ===="
			<< RESET << std::endl;
		identify(obj);
		identify(*obj);
		delete obj;
	}
}
