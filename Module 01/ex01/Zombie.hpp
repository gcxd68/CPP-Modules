/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:22:48 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/29 13:22:50 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {

public:
	// Destructor
	~Zombie( void );

	// Public method(s)
	void		announce( void );
	void		setName( const std::string& newName );

private:
	// Attribute(s)
	std::string	_name;

};

Zombie*	zombieHorde( int N, std::string name );

#endif
