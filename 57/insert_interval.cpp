#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        bool inserted = false;
        for (size_t i = 0; i < intervals.size(); i++) {
            if (newInterval < intervals[i]) {
                intervals.insert(intervals.begin() + i, newInterval);
                inserted = true;
                break;
            }
        }
        
        if (!inserted) {intervals.insert(intervals.end(), newInterval);}
        
        return merge(intervals);
    }
private:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() <= 1) {return intervals;}
        std::vector<std::vector<int>> output;
        
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
}