# new-class-cpp
Script that makes the process of creating classes easier and faster

## Installation
<b>Use the following commands to install (replace zshrc by bashrc or whatever shell you're using):</b>

```bash
git clone https://github.com/lpellier/new-class-cpp.git ~/.new-class-cpp
echo "alias newClass=\"~/.new-class-cpp/newClass\"" >> ~/.zshrc
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
* Inheritance handled (for exactly one base class)

## Usage
To run the script, type:
```bash
newClass <nameOfClass> <numberOfAttributes>
```
If you want a class without any attributes, just type in 0 for numberOfAttributes.
The script will then ask for the types and names of the attributes and create the class files with the appropriate accessors, mutators and so on.


## Example:
<img width="894" alt="Screenshot 2021-06-18 at 17 23 46" src="https://user-images.githubusercontent.com/57676136/122583820-f1a94080-d059-11eb-8e41-73c5891053f5.png">

## Example.cpp
<img width="894" alt="Screenshot 2021-06-18 at 17 32 18" src="https://user-images.githubusercontent.com/57676136/122584891-2c5fa880-d05b-11eb-991c-4378ec477f68.png">
<img width="894" alt="Screenshot 2021-06-18 at 17 32 53" src="https://user-images.githubusercontent.com/57676136/122584956-3e414b80-d05b-11eb-9122-62d4b9103fa7.png">


## Example.hpp
<img width="894" alt="Screenshot 2021-06-18 at 17 18 46" src="https://user-images.githubusercontent.com/57676136/122583663-cde5fa80-d059-11eb-8ec4-6c6655a3e232.png">

## main.cpp
<img width="894" alt="Screenshot 2021-06-18 at 17 18 56" src="https://user-images.githubusercontent.com/57676136/122583676-cfafbe00-d059-11eb-9551-a5f07b00047e.png">
