#include <vector>  // vector

class NumArray {
   public:
    NumArray(std::vector<int>& nums) {
        std::vector<int> initPrefixSum = {0};
        for (int num : nums) {
            initPrefixSum.push_back(num + initPrefixSum.back());
        }
        prefixSum = initPrefixSum;
    }

    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }

   private:
    std::vector<int> prefixSum;
};
