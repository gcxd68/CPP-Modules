/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:20:44 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/13 11:56:10 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	public:

		// Default constructor
		FragTrap(void);

		// Parameterized constructor
		FragTrap(const std::string& name);

		// Copy constructor
		FragTrap(const FragTrap& other);

		// Copy assignment operator
		FragTrap& operator=(const FragTrap& other);

		// Destructor
		~FragTrap(void);

		// Member function(s)
		void	highFivesGuys(void);

	protected:

		// Constant(s)
		static const unsigned int 	DEFAULT_HIT_POINTS = 100;
		static const unsigned int	DEFAULT_ENERGY_POINTS = 100;
		static const unsigned int	DEFAULT_ATTACK_DAMAGE = 30;

};

#endif
