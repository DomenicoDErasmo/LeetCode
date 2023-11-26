#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        
        // counting sort then iterate over
        countingSort(nums);
        
        int result = 1, streak = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            updateResult(nums[i], nums[i-1], result, streak);
        }
        
        return std::max(streak, result);
    }

private:
    void updateResult(const int& current, const int& previous, int& result, int& streak) {
        if (current == previous + 1) {
            streak++;
        } else if (current != previous) {
            if (result < streak) {
                result = streak;
            }
            streak = 1;
        }
    }
    
    void countingSort(std::vector<int>& nums) {
        std::map<int, int> frequencies;
        buildFrequencies(frequencies, nums);
        buildNumsFromFrequencies(nums, frequencies);
    }
    
    void buildFrequencies(std::map<int, int>& frequencies, const std::vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i++) {
            if (frequencies.find(nums[i]) == frequencies.end()) {
                frequencies.insert(std::pair<int, int>(nums[i], 1));
            } else {
                frequencies[nums[i]]++;
            }
        }
    }
    
    void buildNumsFromFrequencies(std::vector<int>& nums, std::map<int, int>& frequencies) {
        int pos = 0;
        for (std::map<int, int>::iterator it = frequencies.begin(); it != frequencies.end(); it++) {
            for (size_t i = 0; i < it->second; i++) {
                nums[pos] = it->first;
                pos++;
            }
        }
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}