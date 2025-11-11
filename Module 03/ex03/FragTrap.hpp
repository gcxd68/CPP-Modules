/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:20:44 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 13:58:52 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {

	public:

		// Default constructor
		FragTrap(void);

		// Parameterized constructor
		FragTrap(const std::string& name);

		// Copy constructor
		FragTrap(const FragTrap& other);

		// Copy assignment operator
		FragTrap&	operator=(const FragTrap& other);

		// Destructor
		~FragTrap(void);

		// Member function(s)
		void	highFivesGuys(void);

};

#endif
