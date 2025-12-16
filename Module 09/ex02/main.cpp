/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:36:47 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/16 13:20:56 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <stdexcept>
#include <vector>

double getTime(void) {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ts.tv_sec * 1000000.0 + ts.tv_nsec / 1000.0;
}

static std::vector<unsigned int> parseInput(int argc, char** argv) {
	if (argc < 2)
		throw std::runtime_error("Error: no input provided");
	std::vector<unsigned int> result;
	for (int i = 1; i < argc; i++) {
		if (!argv[i][0])
			throw std::runtime_error("Error");
		char* end;
		long num = std::strtol(argv[i], &end, 10);
		if (*end || num < 0 || num > std::numeric_limits<unsigned int>::max())
			throw std::runtime_error("Error");
		result.push_back(static_cast<unsigned int>(num));
	}
	return result;
}

template <typename Container>
static void displaySequence(const std::string& label, const Container& seq) {
	std::cout << label;
	for (typename Container::const_iterator it = seq.begin(); it != seq.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

static void verifySort(const UIntDeque& deq, const UIntList& lst) {
	for (size_t i = 1; i < deq.size(); i++)
		if (deq[i - 1] > deq[i])
			throw std::runtime_error("Error: deque not sorted");
	for (UIntList::const_iterator curr = lst.begin(), prev = curr; ++curr != lst.end(); prev = curr)
		if (*prev > *curr)
			throw std::runtime_error("Error: list not sorted");
	if (deq.size() != lst.size())
		throw std::runtime_error("Error: containers have different sizes");
	UIntList::const_iterator lit = lst.begin();
	for (size_t i = 0; i < deq.size(); i++)
		if (deq[i] != *lit++)
			throw std::runtime_error("Error: containers differ");
	std::cout << "Both containers are sorted and identical" << std::endl;
}

int main(int argc, char** argv) {
	try {
		std::vector<unsigned int> data = parseInput(argc, argv);
		displaySequence("Before:", data);

		UIntDeque deqData(data.begin(), data.end());
		double startDeq = getTime();
		PmergeMe pmergeDeq(deqData);
		double endDeq = getTime();
		displaySequence("Deque after: ", pmergeDeq.getDeque());

		UIntList listData(data.begin(), data.end());
		double startList = getTime();
		PmergeMe pmergeList(listData);
		double endList = getTime();
		displaySequence("List after: ", pmergeList.getList());

		verifySort(pmergeDeq.getDeque(), pmergeList.getList());
 
		std::cout
			<< std::fixed << std::setprecision(5)
			<< "Time to process a range of " << data.size()
			<< " elements with std::deque : " << endDeq - startDeq << " us" << std::endl
			<< "Time to process a range of " << data.size()
			<< " elements with std::list  : " << endList - startList << " us" << std::endl;

	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
