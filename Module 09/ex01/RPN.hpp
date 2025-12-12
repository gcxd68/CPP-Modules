/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:17:53 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/12 14:15:21 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN {

	private:

		// Attribute(s)
		std::stack<int> _stack;

		// Core method(s)
		bool	isOperator(char c) const;
		int		performOperation(int a, int b, char op);

	public:

		// Default constructor
		RPN(void);

		// Copy constructor
		RPN(const RPN& other);

		// Copy assignment operator
		RPN& operator=(const RPN& other);

		// Destructor
		~RPN(void);

		// Core method(s)
		int evaluate(const std::string& expression);

};

#endif
