/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:16:58 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/01 11:25:23 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void)
	: _data(NULL)
	, _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n)
	: _data(NULL)
	, _size(n)
{
	if (n)
		this->_data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& other)
	: _data(NULL)
	, _size(other._size)
{
	if (this->_size) {
		this->_data = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_data[i] = other._data[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] this->_data;
		this->_size = other._size;
		if (this->_size) {
			this->_data = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_data[i] = other._data[i];
		} else
			_data = NULL;
	}
	return *this;
}

template <typename T>
Array<T>::~Array(void) {
	delete[] this->_data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size(void) const {
	return this->_size;
}
