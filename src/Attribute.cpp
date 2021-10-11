#include "Attribute.hpp"

//     ____                        _           _   _____                 _   _                  //
//    / ___|__ _ _ __   ___  _ __ (_) ___ __ _| | |  ___|   _ _ __   ___| |_(_) ___  _ __  ___  //
//   | |   / _  |  _ \ / _ \|  _ \| |/ __/ _  | | | |_ | | | |  _ \ / __| __| |/ _ \|  _ \/ __| //
//   | |__| (_| | | | | (_) | | | | | (_| (_| | | |  _|| |_| | | | | (__| |_| | (_) | | | \__ \ //
//    \____\__,_|_| |_|\___/|_| |_|_|\___\__,_|_| |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/ //

Attribute::Attribute(void) {
	// std::cout << "Default constructor called" << std::endl;
	this->_type = "null";
	this->_name = "null";
	this->_accessSpecifier = _VOID;
}

Attribute::Attribute(std::string type, std::vector<std::string> keywords, std::string name, int accessSpecifier) : \
	_type(type), _keywords(keywords), _name(name), _accessSpecifier(accessSpecifier) {
	// std::cout << "Parameter constructor called" << std::endl;
}

Attribute::~Attribute(void) {
	// std::cout << "Destructor called" << std::endl;
}

Attribute::Attribute(Attribute const & src) {
	// std::cout << "Copy constructor called" << std::endl;
	this->_type = src.getType();
	this->_keywords = src.getKeywords();
	this->_name = src.getName();
	this->_accessSpecifier = src.getAccessSpecifier();
}

Attribute & Attribute::operator=(Attribute const & src) {
	// std::cout << "Assignment operator called" << std::endl;
	this->_type = src.getType();
	this->_keywords = src.getKeywords();
	this->_name = src.getName();
	this->_accessSpecifier = src.getAccessSpecifier();
	return *this;
}

//       _                                         //
//      / \   ___ ___ ___  ___ ___  ___  _ __ ___  //
//     / _ \ / __/ __/ _ \/ __/ __|/ _ \| '__/ __| //
//    / ___ \ (_| (_|  __/\__ \__ \ (_) | |  \__ \ //
//   /_/   \_\___\___\___||___/___/\___/|_|  |___/ //

std::string	Attribute::getType() const {
	return this->_type;
}

std::vector<std::string>	Attribute::getKeywords() const {
	return this->_keywords;
}

std::string	Attribute::getName() const {
	return this->_name;
}

int	Attribute::getAccessSpecifier() const {
	return this->_accessSpecifier;
}

//    __  __       _        _                   //
//   |  \/  |_   _| |_ __ _| |_ ___  _ __ ___   //
//   | |\/| | | | | __/ _  | __/ _ \|  __/ __|  //
//   | |  | | |_| | || (_| | || (_) | |  \__ \  //
//   |_|  |_|\__,_|\__\__,_|\__\___/|_|  |___/  //

void	Attribute::setType(std::string type) {
	this->_type = type;
}

void	Attribute::setKeywords(std::vector<std::string> keywords) {
	this->_keywords = keywords;
}

void	Attribute::setName(std::string name) {
	this->_name = name;
}

void	Attribute::setAccessSpecifier(int accessSpecifier) {
	this->_accessSpecifier = accessSpecifier;
}

bool	Attribute::operator<(const Attribute& src) const {
	return (this->_accessSpecifier < src.getAccessSpecifier());
}
