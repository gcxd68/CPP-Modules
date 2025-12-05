/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:27:41 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/05 11:38:20 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

int main() {
	std::cout << MAGENTA "=== TEST 1: MUTANTSTACK VS LIST ===" RESET << std::endl;
	{
		std::cout << "MutantStack:\t";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << " ";  // Should output: 17
		mstack.pop();
		std::cout << mstack.size() << " ";  // Should output: 1
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
			std::cout << *(it++) << " ";
		std::cout << std::endl;
		std::stack<int> s(mstack);
	}
	{
		std::cout << "std::list:\t";
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << " ";  // Should output: 17
		mstack.pop_back();
		std::cout << mstack.size() <<  " ";  // Should output: 1
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
			std::cout << *(it++) << " ";
		std::cout << std::endl;
	}
	{
		std::cout << MAGENTA "\n=== TEST 2: ITERATION ===" RESET << std::endl;
		MutantStack<int> original;
		for (int i = 0; i < 10; i++)
			original.push(i);
		std::cout << "[ Forward iteration ]" << std::endl;
		for (MutantStack<int>::iterator it = original.begin(); it != original.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "[ Reverse iteration ]" << std::endl;
		for (MutantStack<int>::reverse_iterator it = original.rbegin(); it != original.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << MAGENTA "\n=== TEST 3: CONST ITERATION ===" RESET << std::endl;
		std::cout << "[ Const forward iteration ]" << std::endl;
		const MutantStack<int>& const_ref = original;
		for (MutantStack<int>::const_iterator it = const_ref.begin(); it != const_ref.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "[ Const reverse iteration ]" << std::endl;
		for (MutantStack<int>::const_reverse_iterator it = const_ref.rbegin(); it != const_ref.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << MAGENTA "\n=== TEST 4: COPY CONSTRUCTOR ===" RESET << std::endl;
		MutantStack<int> copy1(original);
		std::cout << "Original size is " << original.size() << " before push" << std::endl;
		std::cout << "Copy size is " << copy1.size() << " before push" << std::endl;
		copy1.push(99);
		std::cout << "Original size is " << original.size() << " after push" << std::endl;
		std::cout << "Copy size is " << copy1.size() << " after push" << std::endl;
		
		std::cout << MAGENTA "\n=== TEST 5: COPY ASSIGNMENT OPERATOR ===" RESET << std::endl;
		MutantStack<int> copy2;
		copy2 = original;
		std::cout << "Original size is " << original.size() << " before pop" << std::endl;
		std::cout << "Copy size is " << copy2.size() << " before pop" << std::endl;
		copy2.pop();
		std::cout << "Original size is " << original.size() << " after pop" << std::endl;
		std::cout << "Copy size is " << copy2.size() << " after pop" << std::endl;
	}
}
