/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:35:48 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/04 10:19:27 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

// Function template(s)
template <typename T>
void iter(T* array, const size_t length, void(*function)(T&)) {
	if (!array) return;
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void iter(const T* array, const size_t length, void(*function)(const T&)) {
	if (!array) return;
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

#endif
