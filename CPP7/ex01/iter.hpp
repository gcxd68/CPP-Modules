/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:22:15 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/19 10:10:36 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>

// Templates
template<typename T>
void iter(T *array, size_t length, void(*f)(T &)) {

	if ( array ==  NULL ) return ;
	if ( length == 0 ) return;

	for ( size_t i = 0; i < length; i++) {

		f(array[i]);
	}
}

template<typename T>
void iter(T *array, size_t length, void(*f)(const T &)) {

	if ( array ==  NULL ) return ;
	if ( length == 0 ) return;

	for ( size_t i = 0; i < length; i++) {

		f(array[i]);
	}
}

