#include <vector>  //vector

class NumArray {
   public:
    NumArray(std::vector<int>& nums) {
        std::vector<int> toBuildPrefixSum = {nums.front()};
        for (int i = 1; i < nums.size(); i++) {
            toBuildPrefixSum.push_back(toBuildPrefixSum[i - 1] + nums[i]);
        }
        prefixSum = toBuildPrefixSum;
    }

    int sumRange(int left, int right) {
        return prefixSum[right] - (left == 0 ? 0 : prefixSum[left - 1]);
    }

   private:
    std::vector<int> prefixSum;
};
