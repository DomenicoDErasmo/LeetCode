#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        if (numRows == 0) {return {};}
        if (numRows == 1) {return {{1}};}
        if (numRows == 2) {return {{1}, {1, 1}};}
        std::vector<std::vector<int>> result {
            {1},
            {1, 1}
        };
        for (size_t i = 2; i < numRows; i++) {
            result.push_back({});
            result[i].push_back(1);
            for (size_t j = 1; j < i; j++) {
                result[i].push_back(result[i-1][j-1] + result[i-1][j]);
            }
            result[i].push_back(1);
        }
        return result;
    }
};

std::string vectorToString(std::vector<int> vec) {
    if (vec.size() == 0) {return "[]";}
    std::string result = "[" + std::to_string(vec[0]);
    for (size_t i = 1; i < vec.size(); i++) {
        result += (", " + std::to_string(vec[i]));
    }
    return result + "]";
}

std::string triangleToString(std::vector<std::vector<int>> triangle) {
    if (triangle.size() == 0) {return "[]";}
    std::string result = "[" + vectorToString(triangle[0]);
    for (size_t i = 1; i < triangle.size(); i++) {
        result += (", " + vectorToString(triangle[i]));
    }
    result += "]";
    return result;
}

int main() {
    Solution solution;
    std::cout << "Hello world!" << std::endl;
    std::cout << triangleToString(solution.generate(0)) << std::endl;
    std::cout << triangleToString(solution.generate(1)) << std::endl;
    std::cout << triangleToString(solution.generate(2)) << std::endl;
    std::cout << triangleToString(solution.generate(3)) << std::endl;
    return 0;
}