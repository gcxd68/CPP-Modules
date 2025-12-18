/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:17:56 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/18 13:16:05 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <limits>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

// Default constructor
RPN::RPN(void) {}

// Copy constructor
RPN::RPN(const RPN& other) : _stack(other._stack) {}

// Copy assignment operator
RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
		this->_stack = other._stack;
	return *this;
}

// Destructor
RPN::~RPN(void) {}

// Core method(s)
bool RPN::isOperator(char c) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::performOperation(int a, int b, char op) {
	if (op == '/') {
		if (!b)
			throw std::runtime_error("Error: division by zero");
		float floatRes = static_cast<float>(a) / b;
		if (static_cast<int>(floatRes) != floatRes)
			throw std::runtime_error("Error: non-integer result");
		return floatRes;
	}
	long longRes;
	if (op == '+')
		longRes = a + b;
	else if (op == '-')
		longRes = a - b;
	else
		longRes = a * b;
	if (longRes > std::numeric_limits<int>::max() || longRes < std::numeric_limits<int>::min())
		throw std::runtime_error("Error: integer overflow");
	return longRes;
}

int RPN::evaluate(const std::string& expression) {
	while (!_stack.empty())
		_stack.pop();
	std::istringstream iss(expression);
	std::string token;
	while (iss >> token) {
		if (token.length() != 1)
			throw std::runtime_error("Error: token must be exactly one character");
		char c = token[0];
		if (std::isdigit(c))
			_stack.push(c - '0');
		else if (isOperator(c)) {
			if (_stack.size() < 2)
				throw std::runtime_error("Error: insufficient operands");
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			int result = performOperation(a, b, c);
			_stack.push(result);
		} else
			throw std::runtime_error("Error: only digits (0-9) and operators (+-*/) are allowed");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: insufficient operators");
	return _stack.top();
}
