#include <queue>
#include <vector>


class Solution {
   public:
    std::vector<std::vector<int>> kClosest(
        std::vector<std::vector<int>>& points, int k) {
        auto comparison = [](std::vector<int>& left, std::vector<int>& right) {
            return left[0] * left[0] + left[1] * left[1] >
                   right[0] * right[0] + right[1] * right[1];
        };

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
                            decltype(comparison)>
            queue(comparison, points);

        std::vector<std::vector<int>> result;
        for (int i = 0; i < k; i++) {
            result.push_back(queue.top());
            queue.pop();
        }
        return result;
    }
};
