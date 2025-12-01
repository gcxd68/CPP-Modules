/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:47:28 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/18 11:09:30 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <stdint.h>

struct Data;

class Serializer {

	private:

		// =====================================================================
		// Handlers

		// Default Constructor
		Serializer( void );
		// Copy Constructor
		Serializer( const Serializer &other );
		// Assignation operator
		Serializer&operator=(const Serializer &other);
		// Destructor
		~Serializer( void );

	public:

		// =====================================================================
		// Methods

		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);

};
