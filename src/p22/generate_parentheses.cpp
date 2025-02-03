#include <string>
#include <vector>

class Solution {
   public:
    std::vector<std::string> generateParenthesis(int n) {
        return helper("", n, n);
    }

   private:
    std::vector<std::string> helper(std::string current, int leftRemaining, int rightRemaining) {
        if (leftRemaining < 0 || rightRemaining < 0 || rightRemaining < leftRemaining) {
            return {};
        }
        if (leftRemaining == 0 && rightRemaining == 0) {
            return {current};
        }

        std::vector<std::string> leftResult = helper(current + '(', leftRemaining - 1, rightRemaining);
        std::vector<std::string> rightResult = helper(current + ')', leftRemaining, rightRemaining - 1);

        std::vector<std::string> result;
        result.reserve(leftResult.size() + rightResult.size());
        result.insert(result.end(), leftResult.begin(), leftResult.end());
        result.insert(result.end(), rightResult.begin(), rightResult.end());

        return result;
    }
};
