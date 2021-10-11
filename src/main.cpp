/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:23:34 by lpellier          #+#    #+#             */
/*   Updated: 2021/10/06 20:14:20 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newClass.hpp"

std::vector<Attribute>	readAttributes(int attributeNbr) {
	std::vector<Attribute>		attributes;
	int							i = 0;

	std::cout << CYAN << "You will be asked to enter the information of each of the " << \
		RED << attributeNbr << CYAN << " attributes." << std::endl;
	
	std::string					type;
	std::string					keywords;
	std::string					name;
	int							accessSpecifier;
	while (i < attributeNbr) {
		std::cout << CYAN << "Attribute n°" << RED << i + 1 << CYAN << " :" << std::endl;
		std::cout << "Type : " << RED;
		std::getline(std::cin, type);
		std::cout << CYAN << std::endl << "Keywords (if none, press enter) : " << RED;
		std::getline(std::cin, keywords);
		std::cout << CYAN << std::endl << "Name : " << RED;
		std::cin >> name;
		clearCin();
		std::cout << CYAN << std::endl << "Access Specifier (public is 1, private is 2, protected is 3) : " << RED;
		std::cin >> accessSpecifier;
		std::cout << std::endl;
		clearCin();
		if (!errorInAttributes(type, keywords, name, accessSpecifier)) {
			attributes.push_back(Attribute(type, convertStrVector(keywords), name, accessSpecifier));
			i++;
		}
	}
	return (attributes);
}

int						main(int ac, char **av) {
	if (ac != 3) {
		std::cout << CYAN;
		std::cout << "Please enter a class name followed by the number of attributes when executing the class instantiator program." << std::endl;
		std::cout << RED << "$ " << CYAN << "newClass CLASSNAME ATTRIBUTENBR" << std::endl;
		std::cout << RESET;
		exit(EXIT_FAILURE);
	}

	std::string	className = std::string(av[1]);
	className[0] = toupper(className[0]);
	int			attributeNbr = atoi(av[2]);

	if (errorInClassName(className)) {
		std::cout << "There is an issue with the class name. Please try again." << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string	inheritance;
	std::cout << CYAN << "If your class inherits another, please enter the name of the base class (otherwise press enter): " << RED;
	std::getline(std::cin, inheritance);
	inheritance[0] = toupper(inheritance[0]);
	if (inheritance.find(' ') != inheritance.npos) {
		std::cout << "The Base Class name is incorrect (no spaces)." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::vector<Attribute> attributes = readAttributes(attributeNbr);
	std::sort(attributes.begin(), attributes.end());

	writeHPP(attributes, className, inheritance);
	writeCPP(attributes, className);

	exit(EXIT_SUCCESS);
}