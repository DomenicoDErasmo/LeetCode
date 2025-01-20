#include <vector>

class Solution {
public:
  std::vector<int> getConcatenation(std::vector<int> &nums) {
    std::vector<int> result{nums};

    for (auto it : nums) {
      result.push_back(it);
    }

    return result;
  }
};