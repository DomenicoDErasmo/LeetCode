#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max_profit = 0, min = prices[0], max = prices[0];
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] > max) {
                max = prices[i];
            } else if (prices[i] < min) {
                min = prices[i];
                max = prices[i];
            }
            if (max - min > max_profit) {
                max_profit = max - min;
            }
        }

        return max_profit;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    Solution solution;
    std::vector<int> prices {7, 1, 5, 3, 6, 4};
    std::cout << "Solution: " << solution.maxProfit(prices) << std::endl;
    return 0;
}