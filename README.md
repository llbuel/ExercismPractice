# ExercismPractice

A repository of programming exercises published on [Exercism.org](https://exercism.org). So far, only C++ and x86-64 Assembly exercises are included. 

### C++
Each exercise will include the "[*exercise*].cpp" source file, "[*exercise*].h" header file, and a "test.cpp" source file with test cases for unit testing (the test source contains the program entry point).

Unit testing is done with the [Catch2 library (v2.13.10)](https://github.com/catchorg/Catch2), and the test cases are written by the Exercism contributors.

Cpp directory includes an executable bash script "new\_project.sh" that will create a new subdirectory from the "1\_template" subdirectory, and automate the header/source inclusions.

**NOTE:** Currently, the "new_project" script only works on Linux -- Windows batch port is currently in-work, but there are UNIX->Batch compatibility layers available in the meantime.

### x86-64 Assembly
Each exercise will include the "[*exercise*].asm" source file, a CMake project build file, and a "test.c" source file with test cases for unit testing (the test source contains a wrapper to build the final test binary).

Unit testing is done with the Unity test framework (test cases are written by the Exercism contributors).

x86_64 directory uses CMake to generate the appropriate compilation files and executable.

Because assembly is architecture-dependent, if running on an ARM-based machine (e.g. post-2020 Apple Silicon Mac), an x86 emulator may be needed. QEMU is used for x86 emulation on Linux, while Rosetta 2 is used on macOS (natively invoked when running an x86 program).

Each subdirectory includes a short README to explain the goal of the exercise program, any additional details and requirements, and an example. The test cases defined in "test" are taken as the hard requirements (an exercise solution is only considered successful if it passes all test cases in the test file **as written**, without any modification); for C++/object-oriented languages, this can lead to some off-nominal conventions for classes/naming/implementations/structure.

Each C++ exercise was built using g++ and CMake on Linux/macOS. Each x86 assembly exercise was built using nasm and Make on macOS, and Clang for the C-based test files.

## Installation

Must install Catch2 test library to run any program built from the "test.cpp" file for the C++ exercises. Some programs also use date-time calculations using the [Boost C++ Libraries (v1.80)](https://www.boost.org/) -- these are highlighted in the README for that specific exercise (and build files will also check for the dependencies when building a relevant exercise project).

## Usage

Execute the "new_project" script and enter a name for your new program at the shell prompt. This will generate all the necessary files to build and run the test binary. The output is still just a template + example to get started, and to automate the file structure for consistency -- manual updating is still necessary.

## Contributions

Suggestions for making the code in each exercise more efficient are welcome, but I will only merge PRs at my discretion, as this project is primarily an exercise (hah) in learning C++ in a project-based way.

PRs should be well commented, explaining why one method is better than the one posted -- this is meant as an exercise for learning C++ through simple projects.

## License
[MIT](https://choosealicense.com/licenses/mit/)
