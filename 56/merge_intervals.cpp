#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() <= 1) {return intervals;}
        std::vector<std::vector<int>> output;
        
        std::sort(intervals.begin(), intervals.end());
        output.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            if (output.back()[1] >= intervals[i][0]) {
                output.back()[1] = std::max(output.back()[1], intervals[i][1]);
            } else {
                output.push_back(intervals[i]);
            }
        }
        return output;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}