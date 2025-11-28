/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:16:37 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/28 14:54:23 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base {
   
	public:

		// Destructor
		virtual ~Base(void);

};

// Free function(s)
Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
