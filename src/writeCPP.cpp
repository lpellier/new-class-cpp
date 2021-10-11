/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeCPP.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:13:40 by lpellier          #+#    #+#             */
/*   Updated: 2021/10/07 13:45:08 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newClass.hpp"

void					writeCPP(std::vector<Attribute>& attributes, std::string& className) {
	std::ofstream	fileCPP((className + ".cpp").c_str());
	std::string		upperName;
	int				maxTabNbr = calculateMaxTabs(attributes);
	
	if (!fileCPP) {
		std::cout << "There was an issue with the creation of file " << className << ".cpp" << std::endl;
		exit(EXIT_FAILURE);
	}
	(void)attributes;
	fileCPP << "#include \"" << className << ".hpp\"" << std::endl << std::endl;

	fileCPP << "//                                 _             _        ___                         _                   //" << std::endl;
	fileCPP << "//                                (_)           | |      / __)                    _  (_)                  //" << std::endl;
	fileCPP << "//    ____ _____ ____   ___  ____  _  ____ _____| |    _| |__ _   _ ____   ____ _| |_ _  ___  ____   ___  //" << std::endl;
	fileCPP << "//   / ___|____ |  _ \\ / _ \\|  _ \\| |/ ___|____ | |   (_   __) | | |  _ \\ / ___|_   _) |/ _ \\|  _ \\ /___) //" << std::endl;
	fileCPP << "//  ( (___/ ___ | | | | |_| | | | | ( (___/ ___ | |     | |  | |_| | | | ( (___  | |_| | |_| | | | |___ | //" << std::endl;
	fileCPP << "//   \\____)_____|_| |_|\\___/|_| |_|_|\\____)_____|\\_)    |_|  |____/|_| |_|\\____)  \\__)_|\\___/|_| |_(___/  //" << std::endl << std::endl;

	fileCPP << className << "::" << className << "(void) {" << std::endl;
	fileCPP << "\t// std::cout << \"Default constructor called\" << std::endl;" << std::endl;
	fileCPP << "}" << std::endl << std::endl;
	
	fileCPP << className << "::" << className << "(";
	std::vector<std::string> keywords;
	for (unsigned long i = 0; i < attributes.size(); i++) {
		keywords = attributes[i].getKeywords();
		fileCPP << attributes[i].getType() << " ";
		for (unsigned long i = 0; i < keywords.size(); i++) {
			fileCPP << keywords[i] << " ";
		}
		fileCPP << attributes[i].getName();
		if (i < attributes.size() - 1)
			fileCPP << ", ";
	}
	fileCPP << ") : \\" << std::endl << "\t";
	for (unsigned long i = 0; i < attributes.size(); i++) {
		if (attributes[i].getAccessSpecifier() > 1)
			fileCPP << "_";
		fileCPP << attributes[i].getName() << "(" << attributes[i].getName() << ")";
		if (i < attributes.size() - 1)
			fileCPP << ", ";
	}
	fileCPP << " {" << std::endl;
	fileCPP << "\t// std::cout << \"Parameter constructor called\" << std::endl;" << std::endl;
	fileCPP << "}" << std::endl << std::endl;

	fileCPP << className << "::~" << className << "(void) {" << std::endl;
	fileCPP << "\t// std::cout << \"Destructor called\" << std::endl;" << std::endl;
	fileCPP << "}" << std::endl << std::endl;

	fileCPP << className << "::" << className << "(" << className << " const & src) {" << std::endl;
	fileCPP << "\t// std::cout << \"Copy constructor called\" << std::endl;" << std::endl;
	for (const auto& attribute: attributes) {
		std::string	upperName = attribute.getName();
		upperName[0] = toupper(upperName[0]);
		fileCPP << "\tthis->";
		if (attribute.getAccessSpecifier() > 1)
			fileCPP << "_";
		fileCPP << attribute.getName() << " = src.get" << upperName << "();" << std::endl;
	}
	fileCPP << "}" << std::endl << std::endl;

	fileCPP << className << " & " << className << "::operator=(" << className << " const & src) {" << std::endl;
	fileCPP << "\t// std::cout << \"Assignment operator called\" << std::endl;" << std::endl;
	for (const auto& attribute: attributes) {
		upperName = attribute.getName();
		upperName[0] = toupper(upperName[0]);
		fileCPP << "\tthis->";
		if (attribute.getAccessSpecifier() > 1)
			fileCPP << "_";
		fileCPP << attribute.getName() << " = src.get" << upperName << "();" << std::endl;
	}
	fileCPP << "\treturn *this;" << std::endl << "}" << std::endl << std::endl;

	fileCPP << "//   _____  ____ ____ _____  ___  ___  ___   ____ ___  //" << std::endl;
	fileCPP << "//  (____ |/ ___) ___) ___ |/___)/___)/ _ \\ / ___)___) //" << std::endl;
	fileCPP << "//  / ___ ( (__( (___| ____|___ |___ | |_| | |  |___ | //" << std::endl;
	fileCPP << "//  \\_____|\\____)____)_____|___/(___/ \\___/|_|  (___/  //" << std::endl;

	for (const auto& attribute: attributes) {
		if (attribute.getAccessSpecifier() > 1) {
			fileCPP << std::endl;
			keywords = attribute.getKeywords();
			fileCPP << attribute.getType();
			for (unsigned long i = 0; i < keywords.size(); i++) {
				if (i == 0)
					fileCPP << " ";
				fileCPP << keywords[i];
				if (i < keywords.size() - 1)
					fileCPP << " ";
			}
			upperName = attribute.getName();
			upperName[0] = toupper(upperName[0]);
			fileCPP << printTabs(attribute, maxTabNbr) << className << "::get" << upperName << "(void) const {" << std::endl;
			fileCPP << "\treturn this->_" << attribute.getName() << ";" << std::endl << "}" << std::endl;
		}
	}
	fileCPP << std::endl;

	fileCPP << "//                 _           _                   //" << std::endl;
	fileCPP << "//   ____  _   _ _| |_ _____ _| |_ ___   ____ ___  //" << std::endl;
	fileCPP << "//  |    \\| | | (_   _|____ (_   _) _ \\ / ___)___) //" << std::endl;
	fileCPP << "//  | | | | |_| | | |_/ ___ | | || |_| | |  |___ | //" << std::endl;
	fileCPP << "//  |_|_|_|____/   \\__)_____|  \\__)___/|_|  (___/  //" << std::endl;

	for (const auto& attribute: attributes) {
		if (attribute.getAccessSpecifier() > 1) {
			fileCPP << std::endl << "void";
			keywords = attribute.getKeywords();
			upperName = attribute.getName();
			upperName[0] = toupper(upperName[0]);
			for (int i = 0; i < maxTabNbr - 1; i++) {
				fileCPP << "\t";
			}
			fileCPP << className << "::set" << upperName << "(" << attribute.getType() << " ";
			for (unsigned long i = 0; i < keywords.size(); i++) {
				fileCPP << keywords[i] << " ";
			}
			fileCPP << attribute.getName() << ") {" << std::endl;
			fileCPP << "\tthis->_" << attribute.getName() << " = " << attribute.getName() << ";" << std::endl << "}" << std::endl;
		}
	}
	fileCPP << std::endl;

	fileCPP << "//                     _               _       //" << std::endl;
	fileCPP << "//                 _  | |             | |      //" << std::endl;
	fileCPP << "//   ____  _____ _| |_| |__   ___   __| | ___  //" << std::endl;
	fileCPP << "//  |    \\| ___ (_   _)  _ \\ / _ \\ / _  |/___) //" << std::endl;
	fileCPP << "//  | | | | ____| | |_| | | | |_| ( (_| |___ | //" << std::endl;
	fileCPP << "//  |_|_|_|_____)  \\__)_| |_|\\___/ \\____(___/  //" << std::endl << std::endl;
}