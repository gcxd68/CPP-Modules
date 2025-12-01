/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:24:57 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/21 10:54:07 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind( T &container, int value ) {

	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if ( it != container.end() )
		return it;
	else
		throw std::runtime_error("Element not found in container");
}
