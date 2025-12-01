/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:12:32 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/21 10:36:50 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>

template< typename T>
class MutantStack : public std::stack<T> {

	public:

		// =====================================================================
		// Handlers

		// Default Constructor
		MutantStack( void ) : std::stack<T>() {}

		// Copy Constructor
		MutantStack( const MutantStack &other ) : std::stack<T>(other) {}

		// Assignation operator
		MutantStack&operator=(const MutantStack &other) {

			if (this != &other )
				std::stack<T>::operator=(other);

			return *this;
		}

		// Destructor
		~MutantStack( void ) {}

		// =====================================================================
		// Iterators

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		// =====================================================================
		// Methods

		iterator begin() { return this->c.begin(); }
		const_iterator begin() const { return this->c.begin(); }

		iterator end() { return this->c.end(); }
		const_iterator end() const { return this->c.end(); }
};
