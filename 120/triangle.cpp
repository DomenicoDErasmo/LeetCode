#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        // triangle[i][j] can access triangle [i+1][j] and triangle[i+1][j+1]
        std::vector<std::vector<int>> dp;
        
        // init simple cases
        dp.push_back(std::vector<int>(1, triangle[0][0]));
        
        // init complex cases
        for (size_t i = 1; i < triangle.size(); i++) {
            // first val
            dp.push_back(std::vector<int>(triangle[i].size(), -1));
            dp[i][0] = triangle[i][0] + dp[i-1][0];
            
            // everything in between first and last val
            for (size_t j = 1; j < dp[i].size() - 1; j++) {
                dp[i][j] = triangle[i][j] + std::min(dp[i-1][j-1], dp[i-1][j]);
            }
            
            // last val
            size_t row_size = dp[i].size() - 1;
            dp[i][row_size] = triangle[i][row_size] + dp[i-1][row_size-1];
        }
        
        return *std::min_element(dp[dp.size()-1].begin(), dp[dp.size()-1].end());
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}