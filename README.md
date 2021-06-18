# new-class-cpp
Script that makes the process of creating classes easier and faster

## Installation
<b>Use the following commands to install (replace zshrc by bashrc or whatever shell you're using):</b>

```bash
git clone https://github.com/lpellier/new-class-cpp.git ~/.new-class-cpp
echo "alias newClass=\"bash ~/.new-class-cpp/newClass.sh\"" >> ~/.zshrc
source ~/.zshrc
```

## Features
* File creation : ClassName.cpp, ClassName.hpp, (main.cpp)
* Class is already in canonical form
  * Default constructor
  * Parameter constructor if you want attributes in your class
  * Copy constructor
  * Destructor
  * Operator= assignment
* Accessors (getters) already implemented if you want attributes
* Mutators (setters) already implemented if you want attributes

## Usage
To run the script, type:
```bash
newClass <nameOfClass> <numberOfAttributes>
```
If you want a class without any attributes, just type in 0 for numberOfAttributes.
The script will then ask for the types and names of the attributes and creates the class files with the appropriate accessors, mutators and so on.


## Example:
<img width="1031" alt="Screenshot 2021-06-18 at 17 23 46" src="https://user-images.githubusercontent.com/57676136/122583820-f1a94080-d059-11eb-8e41-73c5891053f5.png">

## Example.cpp
https://user-images.githubusercontent.com/57676136/122583619-beff4800-d059-11eb-989c-57eb31b5ed84.mov

## Example.hpp
<img width="1056" alt="Screenshot 2021-06-18 at 17 18 46" src="https://user-images.githubusercontent.com/57676136/122583663-cde5fa80-d059-11eb-8ec4-6c6655a3e232.png">

# main.cpp
<img width="1056" alt="Screenshot 2021-06-18 at 17 18 56" src="https://user-images.githubusercontent.com/57676136/122583676-cfafbe00-d059-11eb-9551-a5f07b00047e.png">
