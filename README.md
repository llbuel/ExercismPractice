# ExercismPractice

A repository of programming exercises published on [Exercism.org](https://exercism.org). So far, only C++ exercises are included. Each exercise will include the "[*exercise*].cpp" source file, "[*exercise*].h" header file, and a "test.cpp" source file with test cases for unit testing (the test source contains the program entry point).

Unit testing is done with the [Catch2 library (v2.13.10)](https://github.com/catchorg/Catch2), and the test cases are written by the Exercism contributors.

Cpp directory includes an executable bash script "new_project.sh" that will create a new subdirectory from the "1_template" subdirectory, and automate the header/source inclusions.

**NOTE:** For Windows users, use "new_project.bat" instead.

Each subdirectory includes a short README to explain the goal of the program, any additional details and requirements, and an example. The test cases defined in "test.cpp" are taken as the hard requirements.

Each C++ exercise was built using G++.

## Installation

Must install Catch2 test library to run any program that includes a "test.cpp" file. Some programs also use date-time calculations using the [Boost C++ Libraries (v1.80)](https://www.boost.org/).

## Usage

Execute the "new_project" script and enter a name for your new program at the shell prompt. This will create the "\*.cpp" source, "\*.h" header, and "test.cpp", update the namespaces, and `#include` directives. These are just a template to get you started.

Build the files in the created subdirectory **from the test.cpp file (test.cpp contains the main() entry point)**.

Because "test.cpp" contains the program entry point for each exercise, to run just the program without the unit test cases, define an `int main()` in the "[*exercise*].cpp" and remove the `#include "[exercise].cpp"` in "test.cpp" -- if you don't remove the reference, it will try to run a program with two entry points and crash! 

## License
[MIT](https://choosealicense.com/licenses/mit/)
