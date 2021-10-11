/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeHPP.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:13:43 by lpellier          #+#    #+#             */
/*   Updated: 2021/10/07 12:54:18 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newClass.hpp"

void	printPrivateProtected(std::ofstream& fileHPP, std::vector<Attribute>& attributes, int maxTabNbr) {
	bool privateSwitch = false;
	bool protectedSwitch = false;

	for (const auto& attribute: attributes) {
		switch (attribute.getAccessSpecifier()) {
			case 1:
				break;
			case 2:
				if (!privateSwitch) {
					fileHPP << std::endl << "private:" << std::endl;
					fileHPP << "\t" << "// data" << std::endl;
					privateSwitch = true;
				}
				break;
			case 3:
				if (!protectedSwitch) {
					fileHPP << std::endl << "protected:" << std::endl;
					fileHPP << "\t" << "// data" << std::endl;
					protectedSwitch = true;
				}
				break;
		}
		if (attribute.getAccessSpecifier() >= 2) {
			fileHPP << "\t";
			fileHPP << attribute.getType();
			std::vector<std::string> keywords = attribute.getKeywords();
			for (unsigned long i = 0; i < keywords.size(); i++) {
				if (i == 0)
					fileHPP << " ";
				fileHPP << keywords[i];
				if (i < keywords.size() - 1)
					fileHPP << " ";
			}
			fileHPP << printTabs(attribute, maxTabNbr);
			fileHPP << "_" << attribute.getName() << ";" << std::endl;
		}
	}
}

void	printPublic(std::ofstream& fileHPP, std::vector<Attribute>& attributes, int maxTabNbr, std::string& className) {
	std::vector<std::string> keywords;
	fileHPP << std::endl << "public:" << std::endl;

	bool	newline = false;
	bool	publicSwitch = false;
	for (const auto& attribute: attributes) {
		if (attribute.getAccessSpecifier() == 1) {
			if (!publicSwitch) {
				fileHPP << "\t// data" << std::endl;
				publicSwitch = true;
			}
			fileHPP << "\t";
			fileHPP << attribute.getType();
			std::vector<std::string> keywords = attribute.getKeywords();
			for (unsigned long i = 0; i < keywords.size(); i++) {
				if (i == 0)
					fileHPP << " ";
				fileHPP << keywords[i];
				if (i < keywords.size() - 1)
					fileHPP << " ";
			}
			fileHPP << printTabs(attribute, maxTabNbr);
			fileHPP << attribute.getName() << ";" << std::endl;
			newline = true;
		}
	}
	if (newline)
		fileHPP << std::endl;

	fileHPP << "\t// default constructor" << std::endl;
	fileHPP << "\t" << className << "(void);" << std::endl;	

	fileHPP << "\t// parameter constructor" << std::endl;
	fileHPP << "\t" << className << "(";
	for (unsigned long i = 0; i < attributes.size(); i++) {
		fileHPP << attributes[i].getType() << " ";
		keywords = attributes[i].getKeywords();
		for (const auto& keyword: keywords) {
			fileHPP << keyword << " ";
		}
		fileHPP << attributes[i].getName();
		if (i < attributes.size() - 1)
			fileHPP << ", ";
	}
	fileHPP << ");" << std::endl;

	fileHPP << "\t// destructor" << std::endl;
	fileHPP << "\t~" << className << "(void);" << std::endl;

	fileHPP << "\t// copy constructor" << std::endl;
	fileHPP << "\t" << className << "(" << className << " const & src);" << std::endl;

	fileHPP << "\t// assignment operator" << std::endl;
	fileHPP << "\t" << className << " & operator=(" << className << " const & src);" << std::endl << std::endl;

	if (attributes.size() > 0)
		fileHPP << "\t// accessors" << std::endl;
	std::string	upperName;
	for (const auto& attribute: attributes) {
		fileHPP << "\t" << attribute.getType();
		keywords = attribute.getKeywords();
		for (unsigned long i = 0; i < keywords.size(); i++) {
			if (i == 0)
				fileHPP << " ";
			fileHPP << keywords[i];
			if (i < keywords.size() - 1)
				fileHPP << " ";
		}
		fileHPP << printTabs(attribute, maxTabNbr) << "get";
		upperName = attribute.getName();
		upperName[0] = toupper(upperName[0]);
		fileHPP << upperName << "(void) const;" << std::endl;
	}

	if (attributes.size() > 0)
		fileHPP << "\t// mutators" << std::endl;
	for (const auto& attribute: attributes) {
		fileHPP << "\tvoid";
		for (int i = 0; i < maxTabNbr - 1; i++)
			fileHPP << "\t";
		fileHPP << "set";
		upperName = attribute.getName();
		upperName[0] = toupper(upperName[0]);
		fileHPP << upperName << "(" << attribute.getType() << " ";
		keywords = attribute.getKeywords();
		for (const auto& keyword: keywords) {
			fileHPP << keyword << " ";
		}
		fileHPP << attribute.getName() << ");" << std::endl;
	}
	fileHPP << std::endl << "\t// methods" << std::endl;
}

void	writeHPP(std::vector<Attribute>& attributes, std::string& className, std::string& inheritance) {
	std::ofstream	fileHPP((className + ".hpp").c_str());
	int				maxTabNbr = calculateMaxTabs(attributes);

	if (!fileHPP) {
		std::cout << "There was an issue with the creation of file " << className << ".hpp" << std::endl;
		exit(EXIT_FAILURE);
	}

	fileHPP << "#ifndef " << upperString(className) << "_HPP" << std::endl;
	fileHPP << "# define " << upperString(className) << "_HPP" << std::endl << std::endl;

	fileHPP << "#include <iostream>" << std::endl << "#include <string>" << std::endl;
	if (inheritance.compare(""))
		fileHPP << "#include \"" << inheritance << ".hpp\"" << std::endl;
	fileHPP << std::endl;

	fileHPP << "class " << className;
	if (inheritance.compare(""))
		fileHPP << " : public " << inheritance;
	fileHPP << " {";

	printPrivateProtected(fileHPP, attributes, maxTabNbr);
	printPublic(fileHPP, attributes, maxTabNbr, className);

	fileHPP << "};" << std::endl << std::endl;
	fileHPP << "#endif" << std::endl;
}
