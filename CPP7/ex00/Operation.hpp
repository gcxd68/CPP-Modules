/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operation.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:22:15 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/19 09:44:48 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Operation {

	private:
		// =====================================================================
		// Handlers

		// Default Constructor
		Operation( void );
		// Copy Constructor
		Operation( const Operation &other );
		// Assignation operator
		Operation&operator=(const Operation &other);
		// Destructor
		~Operation( void );

	public:

		// =====================================================================
		// Methods

		// Templates
		template<typename T>
		static void swap(T &a, T &b) {

			T temp = a;
			a = b;
			b = temp;
		}

		template<typename T>
		static T min(const T &a, const T &b) {

			if ( a < b )
				return a;
			else
				return b;
		}

		template<typename T>
		static T max(const T &a, const T &b) {

			if ( a > b )
				return a;
			else
				return b;
		}
};
