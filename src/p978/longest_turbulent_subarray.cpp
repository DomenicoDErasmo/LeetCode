#include <vector>  // vector

enum Comparison {
    Equal = 0,
    Less = 1,
    Greater = 2,
};

Comparison compare(int left, int right) {
    if (left == right) {
        return Comparison::Equal;
    } else if (left > right) {
        return Comparison::Greater;
    } else {
        return Comparison::Less;
    }
}

class Solution {
   public:
    int maxTurbulenceSize(std::vector<int>& arr) {
        if (arr.size() == 1) {
            return 1;
        }

        Comparison lastComparison = compare(arr[0], arr[1]);

        int maxLength = 0, curLength = 0;
        for (int i = 1; i < arr.size(); i++) {
            Comparison currentComparison = compare(arr[i - 1], arr[i]);
            bool isTurbulent = (lastComparison != currentComparison &&
                                lastComparison != Comparison::Equal &&
                                currentComparison != Comparison::Equal);
            lastComparison = currentComparison;
            curLength = isTurbulent ? curLength + 1 : (currentComparison != Comparison::Equal ? 2 : 1);
            maxLength = std::max(maxLength, curLength);
        }

        return maxLength;
    }
};
