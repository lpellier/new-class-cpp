/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:55:03 by lpellier          #+#    #+#             */
/*   Updated: 2021/10/07 13:32:06 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newClass.hpp"

std::vector<std::string>		convertStrVector(std::string const & str) {
	std::vector<std::string>	ret;
	std::stringstream			ss(str);
	std::string					s;
	
	while (std::getline(ss, s, ' ')) {
		ret.push_back(s);
	}
	return (ret);
}

void					clearCin() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string				upperString(std::string& str) {
	std::string ret = str;
	unsigned long i = 0;

	while (i < ret.length()) {
		ret[i] = toupper(ret[i]);
		i++;
	}
	return (ret);
}

int						calculateMaxTabs(std::vector<Attribute>& attributes) {
	unsigned long	maxLength = 0;
	int keywordsLength;
	
	for (const auto& attribute: attributes) {
		keywordsLength = 0;
		for (const auto& keyword: attribute.getKeywords()) {
			keywordsLength += keyword.length() + 1;
		}
		if (keywordsLength)
			keywordsLength--;
		if (attribute.getType().length() + keywordsLength > maxLength)
			maxLength = attribute.getType().length() + 1 + keywordsLength;
	}
	return (maxLength / 4 + 1);
}

std::string				printTabs(Attribute attribute, int maxTabNbr) {
	std::string tabs = "";
	int			tabNbr;
	int			attrLength = 0;
	int			keywordsLength = 0;

	for (const auto& keyword: attribute.getKeywords()) {
		keywordsLength += keyword.length() + 1; 
	}
	if (keywordsLength)
		keywordsLength--;
	attrLength = attribute.getType().length() + 1 + keywordsLength;
	tabNbr = maxTabNbr - (attrLength / 4);
	for (int i = 0; i < tabNbr; i++) {
		tabs += "\t";
	}
	return (tabs);
}
