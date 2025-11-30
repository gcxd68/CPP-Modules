/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:22:16 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/30 18:43:20 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span {

	private:

		// Attribute(s)
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:

		// Special member functions
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		// Member functions
		void addNumber(int number);

		// Add a range of iterators to the Span
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end);

		// Core method(s)
		int		shortestSpan() const;
		int		longestSpan() const;

		// Custom exception(s)
		class ContainerFullException : public std::exception {
			virtual const char* what() const throw();
		};

		class NoSpanException : public std::exception {
			virtual const char* what() const throw();
		};

};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
	while (begin != end) {
		if (_numbers.size() >= _maxSize) {
			throw ContainerFullException();
		}
		_numbers.push_back(*begin);
		begin++;
	}
}

#endif
