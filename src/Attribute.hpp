#ifndef ATTRIBUTE_HPP
# define ATTRIBUTE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <fstream>

# define CYAN		"\e[34m"
# define RED		"\e[31m"
# define RESET		"\e[0m"

# define _VOID		0
# define _PUBLIC	1
# define _PRIVATE	2
# define _PROTECTED	3

class Attribute {
private:
	// data
	std::string					_type;
	std::vector<std::string>	_keywords;
	std::string					_name;
	int							_accessSpecifier;

public:
	// default constructor
	Attribute(void);
	// parameter constructor
	Attribute(std::string type, std::vector<std::string> keywords, std::string name, int accessSpecifier);
	// destructor
	~Attribute(void);
	// copy constructor
	Attribute(Attribute const & src);
	// assignment operator
	Attribute &	operator=(Attribute const & src);

	// accessors
	std::string					getType() const;
	std::vector<std::string>	getKeywords() const;
	std::string					getName() const;
	int							getAccessSpecifier() const;
	// mutators
	void						setType(std::string type);
	void						setKeywords(std::vector<std::string> keywords);
	void						setName(std::string name);
	void						setAccessSpecifier(int accessSpecifier);

	// methods
	bool						operator<(const Attribute& src) const;
};

#endif
