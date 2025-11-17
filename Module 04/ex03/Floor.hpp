/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:54:03 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/17 13:50:53 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

class AMateria;

class Floor {

	private:

		// Default constructor
		Floor();

		// Copy constructor
		Floor(const Floor& other);

		// Copy assignment operator
		Floor& operator=(const Floor& other);

		// Destructor
		~Floor();

		// Constant(s)
		static const int MAX_ITEMS = 1024;

		// Attribute(s)
		AMateria*	_items[MAX_ITEMS];
		int			_count;

	public:

		// Accessor(s)
		static Floor& getInstance();

		// Core method(s)
		void add(AMateria* m);

};

#endif
