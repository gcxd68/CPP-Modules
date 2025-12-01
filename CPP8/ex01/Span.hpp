/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:22:12 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/21 10:53:18 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator> // for distance

class Span {

	private:

		unsigned int _N;
		std::vector<int> _numbers;

	public:

		// =====================================================================
		// Handlers

		// Default Constructor
		Span( void );
		// Custom Constructor
		Span( unsigned int N );
		// Copy Constructor
		Span( const Span &other );
		// Assignation operator
		Span&operator=(const Span &other);
		// Destructor
		~Span( void );

		// =====================================================================
		// Getters


		// =====================================================================
		// Methods
		void addNumber( int number );
		unsigned int shortestSpan();
		unsigned int longestSpan();

		// Template
		template<typename Iterator>
		void addNumber( Iterator begin, Iterator end ) {

			// nbr elem to add
			size_t count = std::distance(begin, end);

			// Space left
			if ( _numbers.size() +  count > _N )
				throw SpanFullException();


			// Ad inside
			for ( Iterator it = begin; it != end; it++ )
				_numbers.push_back(*it);
		}

		// =====================================================================
		// Exceptions

		class SpanFullException : public std::exception {
		public:
			virtual const char * what() const throw();
		};

		class NoSpanException : public std::exception {
		public:
			virtual const char * what() const throw();
		};

};

// =============================================================================
// Op overload
