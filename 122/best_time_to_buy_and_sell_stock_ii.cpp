#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int result = 0;
        
        int temp = 0;
        for (size_t i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                result += prices[i] - prices[i-1];   
            }
        }
        
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}