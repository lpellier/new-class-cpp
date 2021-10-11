/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:51:59 by lpellier          #+#    #+#             */
/*   Updated: 2021/10/07 10:39:49 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Attribute.hpp"

std::vector<std::string>	convertStrVector(std::string const & str);

std::vector<Attribute>		readAttributes(int attributeNbr);

bool						errorInClassName(std::string const & className);
bool						errorInAttributes(std::string type, std::string keywords, std::string name, int accessSpecifier);

std::string					upperString(std::string& str);
std::string					printTabs(Attribute attribute, int maxTabNbr);
void						clearCin();
int							calculateMaxTabs(std::vector<Attribute>& attributes);

void						writeHPP(std::vector<Attribute>& attributes, std::string& className, std::string& inheritance);
void						writeCPP(std::vector<Attribute>& attributes, std::string& className);