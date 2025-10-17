/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:59:14 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/29 13:59:15 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
	int N = 7;
	Zombie* horde = zombieHorde(N, "Walker");
	if (!horde)
		return 1;
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
}
