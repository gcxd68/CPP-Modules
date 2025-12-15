/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:36:39 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/15 15:12:50 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static unsigned int jacobsthal(size_t n) {
	if (n > 33)
		return std::numeric_limits<unsigned int>::max();
	unsigned long power = 1UL << n;
	long sign = ((n - 1) % 2) ? -1 : 1;
	return static_cast<unsigned int>((power + sign) / 3);
}

void generateInsertionOrder(size_t n, std::vector<size_t>& order) {
	order.clear();
	if (!n)
		return;
	std::vector<size_t> jacob;
	for (size_t i = 2, jac; (jac = jacobsthal(i)) <= n; i++)
		jacob.push_back(jac);
	size_t prev = 0;
	for (size_t i = 0; i < jacob.size(); prev = jacob[i++])
		for (size_t j = jacob[i]; j > prev; j--)
			if (j <= n)
				order.push_back(j);
	for (size_t j = n; j > prev; j--)
		order.push_back(j);
}
