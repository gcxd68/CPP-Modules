/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:22:16 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/01 15:29:58 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span {

	private:

		// Attribute(s)
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:

		// Default Constructor
		Span(void);
		
		// Parameterized constructor
		Span(unsigned int N);

		// Copy constructor
		Span(const Span& other);

		// Copy assignment operator
		Span& operator=(const Span& other);

		// Destructor
		~Span(void);

		// Core method(s)
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		// Accessor(s)
		void		addNumber(int number);
		size_t		size(void) const;
		int&		operator[](size_t index);
		const int&	operator[](size_t index) const;

		// Function template(s)
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end);

		// Custom exception(s)
		class ContainerFullException : public std::exception {
			virtual const char* what() const throw();
		};

		class NoSpanException : public std::exception {
			virtual const char* what() const throw();
		};

		class OutOfRangeException : public std::exception {
			virtual const char* what() const throw();
		};

};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
	while (begin != end) {
		if (_numbers.size() >= _maxSize)
			throw ContainerFullException();
		_numbers.push_back(*begin++);
	}
}

#endif
