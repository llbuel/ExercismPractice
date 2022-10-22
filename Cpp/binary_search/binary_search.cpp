#include "binary_search.h"

namespace binary_search {

std::size_t find(std::vector<int> array, std::size_t searchKey) {
    if (array.size() > 0) {
        std::size_t arrayLength{ array.size() };
        std::size_t testLength{ arrayLength };
        std::size_t keyTest;
        std::size_t keyLocation;
        std::vector<int>::iterator searchItr{ array.begin() };

        std::size_t arrayStart = array.at(searchItr - array.begin());
        std::size_t arrayEnd = array.at(array.size() - 1);

        bool keyFound{ false };

        if (arrayLength == 1) {
            searchItr = array.begin();
            keyTest = *searchItr;

            if (keyTest != searchKey) {
                throw std::domain_error("\nGiven element is not a member of the array.\n");
            }
        }
        else if (searchKey == arrayStart) {
            searchItr = array.begin();
            keyTest = arrayStart;
            keyFound = true;
        }
        else if (searchKey == arrayEnd) {
            searchItr = array.begin() + (array.size() - 1);
            keyTest = arrayEnd;
            keyFound = true;
        }
        else {
            testLength = (testLength / 2);
            searchItr = array.begin() + testLength;

            keyTest = *searchItr;

            while ((testLength > 0) && (searchItr >= array.begin()) && (searchItr <= array.end())) {
                testLength = (testLength / 2);

                if (keyTest > searchKey) {
                    if (testLength == 0) {
                        searchItr -= 1;
                    }
                    else {
                        searchItr -= testLength;
                    }
                }
                else {
                    if (testLength == 0) {
                        searchItr += 1;
                    }
                    else {
                        searchItr += testLength;
                    }
                }

                keyTest = *searchItr;

                if (keyTest == searchKey) {
                    keyFound = true;
                    break;
                }
            }

            if (!keyFound) {
                throw std::domain_error("\nGiven element is not a member of the array.\n");
            }
        }

        keyLocation = (searchItr - array.begin());

        return keyLocation;
    }
    else {
        throw std::domain_error("\nArray must have at least one member.\n");
    }
}

}