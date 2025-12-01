/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:17:01 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/01 11:12:05 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <typename T>
class Array {

	private:

		T*              _data;
		unsigned int    _size;

	public:

		// Default constructor
		Array(void);

		// Parameterized constructor
		Array(unsigned int n);

		// Copy constructor
		Array(const Array& other);

		// Copy assignment operator
		Array& operator=(const Array& other);

		// Destructor
		~Array(void);

		// Bracket operator overload
		T&			operator[](unsigned int index);
		const T&	operator[](unsigned int index) const;

		// core method(s)
		unsigned int size(void) const;

};

# include "Array.tpp"

#endif
