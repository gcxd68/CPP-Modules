/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:08:09 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/20 11:22:22 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdexcept>

template<typename T>
class Array {

	private:

		// BDD type T
		T *_data;

		// Size of array
		unsigned int _size;

	public:

		// =====================================================================
		// Handlers

		// Default Constructor
		Array( void );
		// Custom Constructor
		Array( unsigned int n );
		// Copy Constructor
		Array( const Array<T> &other );
		// Assignation operator
		Array<T>&operator=(const Array<T> &other) {

			if ( this != &other ) {

				delete[] this->_data;
				this->_size = other._size;
				this->_data = new T[_size];

				for ( unsigned int i = 0; i < _size; i++ )
					this->_data[i] = other._data[i];
			}
			return *this;
		}

		// Destructor
		~Array( void );

		// =====================================================================
		// Indexation op

		T &operator[](unsigned int index) {

			if ( index >= this->_size )
				throw std::out_of_range("Index out of range.");

			return this->_data[index];
		}

		const T &operator[](unsigned int index) const {

			if ( index >= this->_size )
				throw std::out_of_range("Index out of range.");

			return this->_data[index];
		}

		// =====================================================================
		// Getter

		unsigned int size() const {

			return this->_size;
		}

};

// =============================================================================
// Template implementation

// Default constructor
template<typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

// Custom constructor
template<typename T>
Array<T>::Array( unsigned int n ) : _size(n) {

	_data = new T[n];
}

// Copy constructor
template<typename T>
Array<T>::Array( const Array<T> &other ) {

	this->_size = other._size;
	this->_data = new T[_size];

	for ( unsigned int i = 0; i < _size; i++ )
		this->_data[i] = other._data[i];
}

// Destructor
template<typename T>
Array<T>::~Array() {

	delete[] _data;
}
