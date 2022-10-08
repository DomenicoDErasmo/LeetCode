#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        // O(nums1.size() * nums2.size())
        std::vector<int> result;
        
        for (size_t i = 0; i < nums1.size(); i++) {
            int start;
            
            // find start value
            for (start = 0; start < nums2.size(); start++) {
                if (nums2[start] == nums1[i]) {
                    break;
                }
            }
            
            // find the next biggest
            bool found = false;
            for (start = start + 1; start < nums2.size(); start++) {
                if (nums2[start] > nums1[i]) {
                    result.push_back(nums2[start]);
                    found = true;
                    break;
                }
            }
            
            // case of none bigger found
            if (!found) {
                result.push_back(-1);
            }
        }
        
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}