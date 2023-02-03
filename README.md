# ExercismPractice

A repository of programming exercises published on [Exercism.org](https://exercism.org). So far, only C++ exercises are included. Each exercise will include the "[*exercise*].cpp" source file, "[*exercise*].h" header file, and a "test.cpp" source file with test cases for unit testing (the test source contains the program entry point).

Unit testing is done with the [Catch2 library (v2.13.10)](https://github.com/catchorg/Catch2), and the test cases are written by the Exercism contributors.

Cpp directory includes an executable bash script "new\_project.sh" that will create a new subdirectory from the "1\_template" subdirectory, and automate the header/source inclusions.

**NOTE:** Currently, the "new_project" script only works on Linux -- Windows batch port is currently in-work, but there are UNIX->Batch compatibility layers available in the meantime.

Each subdirectory includes a short README to explain the goal of the exercise program, any additional details and requirements, and an example. The test cases defined in "test.cpp" are taken as the hard requirements (an exercise solution is only considered successful if it passes all test cases in "test.cpp" **as written**, without any modification); this can lead to some non-standard naming conventions for classes/implementations/structure.

Each C++ exercise was built using g++.

## Installation

Must install Catch2 test library to run any program built from the "test.cpp" file. Some programs also use date-time calculations using the [Boost C++ Libraries (v1.80)](https://www.boost.org/) -- these are highlighted in the README for that specific exercise.

## Usage

Execute the "new_project" script and enter a name for your new program at the shell prompt. This will create the "\*.cpp" source, "\*.h" header, and "test.cpp", update the namespaces, and `#include` directives. These are just a template + example to get you started, and to automate the file structure for consistency.

Build ***all*** the files in the subdirectory for the given exercise **(test.cpp contains the main() entry point)**. If you only build the active file, either the program will crash because the exercise source does not contain an entry point, or the program will crash because the linker will not automatically link to the exercise source file, which contains all of the definitions referenced in the header file (will result in undefined errors upon compiling).

Because "test.cpp" contains the program entry point for each exercise, to run just the program without the unit test cases, define an `int main()` in the "[*exercise*].cpp" and remove the `#include "[exercise].h"` in "test.cpp" -- if you don't remove the reference, it will try to run a program with two entry points, which is bad-news-bears! 

**TL;DR:** Either build all source files for a given exercise before running (done automatically by MS Visual Studio), or make sure to write your own `int main()` entry point in the exercise source file to just build and run that one. Do not build all from the parent "/Cpp/" directory, as you will then have *multiple* entry points.

## Contributions

Suggestions for making the code in each exercise more efficient are welcome, but I will only merge PRs at my discretion, as this project is primarily an exercise (hah) in learning C++ in a project-based way.

PRs should be well commented, explaining why one method is better than the one posted -- this is meant as an exercise for learning C++ through simple projects.

## License
[MIT](https://choosealicense.com/licenses/mit/)
