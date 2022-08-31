#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {return {1};}
        if (rowIndex == 1) {return {1, 1};}
        std::vector<std::vector<int>> triangle {
            {1},
            {1, 1}
        };
        for (size_t i = 2; i <= rowIndex; i++) {
            triangle.push_back({});
            triangle[i].push_back(1);
            for (size_t j = 1; j < i; j++) {
                triangle[i].push_back(triangle[i-1][j-1] + triangle[i-1][j]);
            }
            triangle[i].push_back(1);
        }
        return triangle[rowIndex];
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}