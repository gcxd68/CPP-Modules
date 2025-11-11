/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:25:54 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 13:58:36 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:

		// Default constructor
		ScavTrap(void);

		// Parameterized constructor
		ScavTrap(const std::string& name);

		// Copy constructor
		ScavTrap(const ScavTrap& other);

		// Copy assignment operator
		ScavTrap&	operator=(const ScavTrap& other);

		// Destructor
		~ScavTrap(void);

		// Member function(s)
		void	attack(const std::string& target); // override
		void	guardGate(void);

};

#endif
