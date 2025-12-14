/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:36:47 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/14 18:14:14 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <stdexcept>

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

static void verifySort(const std::deque<unsigned int>& deq, const std::list<unsigned int>& lst) {
	for (size_t i = 1; i < deq.size(); i++)
		if (deq[i - 1] > deq[i])
			throw std::runtime_error("Error: deque not sorted");
	for (std::list<unsigned int>::const_iterator curr = lst.begin(), prev = curr; ++curr != lst.end(); prev = curr)
		if (*prev > *curr)
			throw std::runtime_error("Error: list not sorted");
	if (deq.size() != lst.size())
		throw std::runtime_error("Error: containers have different sizes");
	std::list<unsigned int>::const_iterator lit = lst.begin();
	for (size_t i = 0; i < deq.size(); i++)
		if (deq[i] != *lit++)
			throw std::runtime_error("Error: containers differ");
}

int main(int argc, char** argv) {
	try {
		std::vector<unsigned int> data = parseInput(argc, argv);
		displaySequence("Before:", data);

		std::deque<unsigned int> deqData(data.begin(), data.end());
		PmergeMe<std::deque<unsigned int> > pmergeDeq(deqData);
		double startDeq = getTime();
		pmergeDeq.sort();
		double endDeq = getTime();
		displaySequence("Deque after: ", pmergeDeq.getContainer());

		std::list<unsigned int> listData(data.begin(), data.end());
		PmergeMe<std::list<unsigned int> > pmergeList(listData);
		double startList = getTime();
		pmergeList.sort();
		double endList = getTime();
		displaySequence("List after: ", pmergeList.getContainer());

		verifySort(pmergeDeq.getContainer(), pmergeList.getContainer());

		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Time to process a range of " << data.size()
				  << " elements with std::deque : " << endDeq - startDeq << " us" << std::endl;
		std::cout << "Time to process a range of " << data.size()
				  << " elements with std::list  : " << endList - startList << " us" << std::endl;

	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
