/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:03:43 by gdosch            #+#    #+#             */
/*   Updated: 2025/10/28 09:03:44 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int errorExit(const std::string& msg) {
	std::cout << msg << std::endl;
	return 1;
}

std::string replaceAll(const std::string& str, const std::string& s1, const std::string& s2) {
	if (s1.empty()) return str;
	std::string result;
	size_t pos = 0;
	size_t found;
	while ((found = str.find(s1, pos)) != std::string::npos) {
		result.append(str, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(str, pos, str.length() - pos);
	return result;
}

int main(int argc, char** argv) {
	if (argc != 4)
		return errorExit("Usage: " + std::string(argv[0]) + " <filename> <s1> <s2>");
	std::ifstream infile(argv[1], std::ios::binary);
	if (!infile.is_open())
		return errorExit("Error: cannot open file '" + std::string(argv[1]) + "'");
	std::stringstream buffer;
	buffer << infile.rdbuf();
	infile.close();
	std::string result = replaceAll(buffer.str(), argv[2], argv[3]);
	std::string outfilename = std::string(argv[1]) + ".replace";
	std::ofstream outfile(outfilename.c_str(), std::ios::binary);
	if (!outfile.is_open())
		return errorExit("Error: cannot create file '" + outfilename + "'");
	outfile << result;
	outfile.close();
}
