#include <queue>
#include <vector>

class Solution {
   public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::less<int>> queue(
            std::less<int>(), nums);

        for (int i = 1; i < k; i++) {
            queue.pop();
        }

        return queue.top();
    }
};
