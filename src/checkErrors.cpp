/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkErrors.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:49:30 by lpellier          #+#    #+#             */
/*   Updated: 2021/10/06 18:21:53 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newClass.hpp"

bool	errorInClassName(std::string const & className) {
	(void)className;
	if (className.find(' ') != className.npos)
		return (true);
	return (false);
}

bool	errorInAttributes(std::string type, std::string keywords, std::string name, int accessSpecifier) {
	(void)type;
	(void)keywords;
	(void)name;

	if (accessSpecifier < 0 || accessSpecifier > 3)
		return (true);
	return (false);
}
