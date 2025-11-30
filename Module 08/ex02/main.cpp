/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:27:41 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/30 19:01:33 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

int main() {
	std::cout << MAGENTA "=== TEST 1: WITH MUTANTSTACK ===" RESET << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;  // Should output: 17
		mstack.pop();
		std::cout << mstack.size() << std::endl;  // Should output: 1
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
			std::cout << *(it++) << std::endl;
		// MutantStack should be compatible with std::stack
		std::stack<int> s(mstack);
	}

	std::cout << MAGENTA "\n=== TEST 2: WITH STD::LIST (FOR COMPARISON) ===" RESET << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;  // Should output: 17
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;  // Should output: 1
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
			std::cout << *(it++) << std::endl;
	}

	std::cout << MAGENTA "\n=== ADDITIONAL TESTS ===" RESET << std::endl;
	{
		MutantStack<int> mstack;
		for (int i = 0; i < 10; ++i)
			mstack.push(i);
		std::cout << "Forward iteration:" << std::endl;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "Reverse iteration:" << std::endl;
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		MutantStack<int> mstack2(mstack);
		std::cout << "Copy - size: " << mstack2.size() << std::endl;
		mstack2.push(99);
		std::cout << "Original size: " << mstack.size() << ", Copy size: " << mstack2.size() << std::endl;
	}
}
