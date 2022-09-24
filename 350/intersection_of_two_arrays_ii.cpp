#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> result;
        std::unordered_map<int, int> nums1_frequencies, nums2_frequencies;
        
        build_frequencies(nums1_frequencies, nums1);
        build_frequencies(nums2_frequencies, nums2);
        
        // Iterate over nums1_frequencies and find keys also in nums2_frequencies
        for (std::unordered_map<int, int>::iterator iter = nums1_frequencies.begin(); iter != nums1_frequencies.end(); iter++) {
            if (nums2_frequencies.find(iter->first) != nums2_frequencies.end()) {
                for (int i = 0; i < min(nums1_frequencies[iter->first], nums2_frequencies[iter->first]); i++) {
                    result.push_back(iter->first);
                }
            }
        }
        return result;
    }
private:
    void build_frequencies(std::unordered_map<int, int>& frequencies, const std::vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i++) {
            if (frequencies.find(nums[i]) == frequencies.end()) {
                frequencies.insert({nums[i], 1});
            } else {
                frequencies[nums[i]]++;
            }
        }
    }
    
    int min(int left, int right) {return left < right ? left : right;}
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}