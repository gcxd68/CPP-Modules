/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:58:42 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 14:15:33 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {

	public:

		// Default constructor
		Brain(void);

		// Parameterized constructor
		Brain(const std::string& type);

		// Copy constructor
		Brain(const Brain& other);

		// Copy assignment operator
		Brain& operator=(const Brain& other);

		// Destructor
		~Brain(void);

	private:

		//Attributes
		std::string ideas[100];

};

#endif
