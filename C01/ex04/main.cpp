/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/16 11:13:01 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/09/01 15:48:05 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int		print_error(std::string str) {
	std::cout << str << std::endl;
	return 1;
}

std::string	find_replace(std::string line, std::string s1, std::string s2) {
	std::string	newline(line);
	size_t		i;
	
	while ((i = newline.find(s1)) != newline.npos) {
		if ((newline.length() - i) > s1.length())
			newline = newline.substr(0, i) + s2 + newline.substr(i + s1.length(), newline.npos);
		else
			newline = newline.substr(0, i) + s2;
	}
	return newline;
}

int	main(int argc, char **argv) {
	
	if (argc != 4)
		return print_error("Error, incorrect number of arguments");
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	if (s2.find(s1) != s2.npos)
		return print_error("Error, s2 contains s1 this will cause an in infinite loop");
	std::string		filename(argv[1]);
	std::ifstream	inFile(filename);
	if (!inFile)
		return print_error("Error, unable to find or open inputFile");
	std::ofstream	outFile(filename + ".replace");
	if (!outFile)
		return print_error("Error creating or overwriting outfile");
	std::string line;
	while(getline(inFile, line))
		outFile << find_replace(line, s1, s2) << std::endl;
	inFile.close();
	outFile.close();
	
	return 0;
}

