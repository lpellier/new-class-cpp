#!/bin/bash

BLUE="\e[34m"
RED="\e[31m"
RESET="\e[0m"

if [ -z "$1" ] || [ -z "$2" ]
then
	printf "${BLUE}Please enter a class name followed by the number of attributes when executing the class instantiator program.\n${RESET}"
	exit 1
fi

className=$1
className=${className^}

attributesNbr=$2
declare -a attrTypes
declare -a attrNames

if [ "${attributesNbr}" -eq "0" ]
then
	attributesNbr="0"
else
	for i in $(seq 0 $(expr ${attributesNbr} - 1))
	do
		printf "${BLUE}Attribute ${RED}${i}\n"
		printf "${BLUE}Please input the type : ${RED}"
		read curType
		attrTypes+=(${curType})
		printf "${BLUE}Please input the name : ${RED}"
		read curName
		attrNames+=("_"${curName})
	done
fi

printf "${BLUE}Would you like to create a main ? [y / n]${RED}\n" 
read -n1 -s answer

if [ "$answer" == "y" ] || [ "$answer" == "Y" ]
then
printf "y\n${RESET}"
	rm -rf main.cpp
	touch main.cpp
	printf "#include \"${className}.hpp\"\n" >> main.cpp
	printf "\nint	main(int ac, char **av) {\n	(void)ac;\n	(void)av;\n}\n" >> main.cpp
else
	printf "n\n"
fi

rm -rf ${className}.hpp ${className}.cpp
printf "${BLUE}New files created\n${RESET}"
touch ${className}.hpp ${className}.cpp

defaultIncludes=(iostream string)

for item in ${defaultIncludes[*]}
do
	printf "#include <${item}>\n" >> ${className}.hpp
done

printf "\nclass ${className} {\nprivate:\n	// data\n" >> ${className}.hpp
if [ ${attributesNbr} -gt 0 ]
then
	for i in $(seq 0 $(expr ${attributesNbr} - 1))
	do
		printf "	%-20s${attrNames[i]};\n" ${attrTypes[i]} >> ${className}.hpp
	done
fi
printf "\npublic:\n"  >> ${className}.hpp
printf "	// default constructor\n	%-20s(void);\n" ${className} >> ${className}.hpp

if [ ${attributesNbr} -gt 0 ]
then
	printf "	// parameter constructor\n	%-20s(" ${className} >> ${className}.hpp
	for i in $(seq 0 $(expr ${attributesNbr} - 1))
	do
		printf "${attrTypes[i]} ${attrNames[i]#?}" >> ${className}.hpp
		if [ $i -lt $(expr ${attributesNbr} - 1) ]
		then
			printf ", " >> ${className}.hpp
		fi
	done
	printf ");\n" >> ${className}.hpp
fi

printf "	// destructor\n	~%-20s(void);\n" ${className} >> ${className}.hpp

printf "	// copy constructor\n	%-20s(${className} const & src);\n" ${className} >> ${className}.hpp

printf "	// assignment operator\n	%-20s & operator=(${className} const & src);\n\n" ${className} >> ${className}.hpp

if [ ${attributesNbr} -gt 0 ]
then
	printf "	// accessors\n" >> ${className}.hpp
	for i in $(seq 0 $(expr ${attributesNbr} - 1))
	do
		curName=${attrNames[i]#?}
		printf "	%-20sget${curName^}() const;\n" ${attrTypes[i]} >> ${className}.hpp
	done
fi

if [ ${attributesNbr} -gt 0 ]
then
	printf "	// mutators\n" >> ${className}.hpp
	for i in $(seq 0 $(expr ${attributesNbr} - 1))
	do
		curName=${attrNames[i]#?}
		printf "	%-20sset${curName^}(${attrTypes[i]} ${curName});\n" "void" >> ${className}.hpp
	done
fi
printf "\n	// methods\n" >> ${className}.hpp

printf "};\n" >> ${className}.hpp

printf "#include \"%s.hpp\"\n\n" ${className} >> ${className}.cpp
printf "//     ____                        _           _   _____                 _   _                  //\n" >> ${className}.cpp
printf "//    / ___|__ _ _ __   ___  _ __ (_) ___ __ _| | |  ___|   _ _ __   ___| |_(_) ___  _ __  ___  //\n" >> ${className}.cpp
printf "//   | |   / _  |  _ \ / _ \|  _ \| |/ __/ _  | | | |_ | | | |  _ \ / __| __| |/ _ \|  _ \/ __| //\n" >> ${className}.cpp
printf "//   | |__| (_| | | | | (_) | | | | | (_| (_| | | |  _|| |_| | | | | (__| |_| | (_) | | | \__ \ //\n" >> ${className}.cpp
printf "//    \____\__,_|_| |_|\___/|_| |_|_|\___\__,_|_| |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/ //\n\n" >> ${className}.cpp

printf "${className}::${className}(void) {\n	std::cout << \"Default constructor called\" << std::endl;\n}\n\n" >> ${className}.cpp
if [ ${attributesNbr} -gt 0 ]
then
	printf "${className}::${className}(" >> ${className}.cpp
	for i in $(seq 0 $(expr ${attributesNbr} - 1))
	do
		printf "${attrTypes[i]} ${attrNames[i]#?}" >> ${className}.cpp
		if [ $i -lt $(expr ${attributesNbr} - 1) ]
		then
			printf ", " >> ${className}.cpp
		fi
	done
	printf ") : " >> ${className}.cpp
	for i in $(seq 0 $(expr ${attributesNbr} - 1))
	do
		printf "${attrNames[i]}(${attrNames[i]#?})" >> ${className}.cpp
		if [ $i -lt $(expr ${attributesNbr} - 1) ]
		then
			printf ", " >> ${className}.cpp
		fi
	done
	printf " {\n	std::cout << \"Parameter constructor called\" << std::endl;\n}\n\n" >> ${className}.cpp
fi
printf "${className}::~${className}(void) {\n	std::cout << \"Destructor called\" << std::endl;\n}\n\n" >> ${className}.cpp
printf "${className}::${className}(${className} const & src) {\n	std::cout << \"Copy constructor called\" << std::endl;\n" >> ${className}.cpp
if [ ${attributesNbr} -gt 0 ]
then
	for i in $(seq 0 $(expr ${attributesNbr} - 1))
	do
		curName=${attrNames[i]#?}
		printf "	this->${attrNames[i]} = src.get${curName^}();\n" >> ${className}.cpp
	done
fi
printf "}\n\n" >> ${className}.cpp
printf "${className} & ${className}::operator=(${className} const & src) {\n	std::cout << \"Assignment operator called\" << std::endl;\n" >> ${className}.cpp
if [ ${attributesNbr} -gt 0 ]
then
	for i in $(seq 0 $(expr ${attributesNbr} - 1))
	do
		curName=${attrNames[i]#?}
		printf "	this->${attrNames[i]} = src.get${curName^}();\n" >> ${className}.cpp
	done
fi
printf "	return *this;\n}\n\n" >> ${className}.cpp

if [ ${attributesNbr} -gt 0 ]
then
	printf "//       _                                         //\n" >> ${className}.cpp
	printf "//      / \   ___ ___ ___  ___ ___  ___  _ __ ___  //\n" >> ${className}.cpp
	printf "//     / _ \ / __/ __/ _ \/ __/ __|/ _ \| '__/ __| //\n" >> ${className}.cpp
	printf "//    / ___ \ (_| (_|  __/\__ \__ \ (_) | |  \__ \ //\n" >> ${className}.cpp
	printf "//   /_/   \_\___\___\___||___/___/\___/|_|  |___/ //\n\n" >> ${className}.cpp                                               
	for i in $(seq 0 $(expr ${attributesNbr} - 1))
	do
		curName=${attrNames[i]#?}
		printf "%-20s${className}::get${curName^}() const {\n	return this->${attrNames[i]};\n}\n\n" ${attrTypes[i]} >> ${className}.cpp
	done
	printf "//    __  __       _        _                   //\n" >> ${className}.cpp
	printf "//   |  \/  |_   _| |_ __ _| |_ ___  _ __ ___   //\n" >> ${className}.cpp
	printf "//   | |\/| | | | | __/ _  | __/ _ \|  __/ __|  //\n" >> ${className}.cpp
	printf "//   | |  | | |_| | || (_| | || (_) | |  \__ \\ //\n" >> ${className}.cpp
	printf "//   |_|  |_|\__,_|\__\__,_|\__\___/|_|  |___/  //\n\n" >> ${className}.cpp
	for i in $(seq 0 $(expr ${attributesNbr} - 1))
	do
		curName=${attrNames[i]#?}
		printf "%-20s${className}::set${curName^}(${attrTypes[i]} ${curName}) {\n	this->${attrNames[i]} = ${curName};\n}\n\n" "void" >> ${className}.cpp
	done
fi

printf "${RED}Done\n${RESET}"

exit 0
