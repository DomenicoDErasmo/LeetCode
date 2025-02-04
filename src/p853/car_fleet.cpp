#include <algorithm>
#include <stack>
#include <vector>

class Solution {
   public:
    int carFleet(int target, std::vector<int>& position,
                 std::vector<int>& speed) {
        std::vector<std::pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        std::stable_sort(cars.begin(), cars.end(), std::greater<>());

        std::stack<double> times;
        for (int i = 0; i < cars.size(); i++) {
            double time = (target - cars[i].first) / double(cars[i].second);
            if (times.empty() || time > times.top()) {
                times.push(time);
            }
        }

        return times.size();
    }
};