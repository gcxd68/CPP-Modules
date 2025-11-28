/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:18:41 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/28 13:09:46 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <string>

struct Data;

class Serializer {

	private:

		// Unused special member functions
		Serializer(void);
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);
		~Serializer(void);

	public:

		// Core method(s)
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

};

#endif
