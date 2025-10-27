/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:31:25 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/30 11:31:26 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Free function(s)
Zombie*	zombieHorde(int N, std::string name) {
	if (N <= 0)
		return NULL;
	Zombie* horde = new(std::nothrow) Zombie[N];
	if (!horde)
		return NULL;
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return horde;
}
