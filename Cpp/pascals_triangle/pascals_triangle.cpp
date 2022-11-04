#include "pascals_triangle.h"

namespace pascals_triangle {

std::vector<std::vector<int>> generate_rows(int rowCount) {
    std::vector<std::vector<int>> triangle;

    if (rowCount == 1) {
        triangle.push_back({1});
    }
    else if (rowCount == 2) {
        triangle.push_back({1});
        triangle.push_back({1,1});
    }
    else if (rowCount > 2) {
        triangle = generate_rows(2);

        for (int i = 2; i < rowCount; ++i) {
            triangle.push_back({});
            triangle[i].push_back(1);

            for (int j = 0; j < (i-1); ++j) {
                triangle[i].push_back(triangle[i-1][j]+triangle[i-1][j+1]);
            }

            triangle[i].push_back(1);
        }
    }

    return triangle;
}

}