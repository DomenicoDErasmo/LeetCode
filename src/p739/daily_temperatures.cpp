#include <stack>
#include <vector>

class Solution {
   public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<std::pair<int, int>> currentTemps;
        currentTemps.push({temperatures.front(), 0});
        for (int i = 1; i < temperatures.size(); i++) {
            while (!currentTemps.empty() && temperatures[i] > currentTemps.top().first) {
                auto top = currentTemps.top();
                result[top.second] = i - top.second;
                currentTemps.pop();
            }
            currentTemps.push({temperatures[i], i});
        }

        return result;
    }
};
