#include <vector>  // max, vector

enum Comparison {
    Less = 0,
    Equal = 1,
    Greater = 2,
};

Comparison compare(int left, int right) {
    if (left < right) {
        return Comparison::Less;
    } else if (left == right) {
        return Comparison::Equal;
    } else {
        return Comparison::Greater;
    }
}

int lengthFromComparison(Comparison current, Comparison previous,
                         int currentLength) {
    if (current == Comparison::Equal) {
        return 1;
    } else if (current == previous) {
        return 2;
    } else {
        return currentLength + 1;
    }
}

class Solution {
   public:
    int maxTurbulenceSize(std::vector<int>& arr) {
        int maxLength = 1, currentLength = 1;
        Comparison previous = Comparison::Equal;
        for (int i = 1; i < arr.size(); i++) {
            Comparison current = compare(arr[i - 1], arr[i]);
            currentLength =
                lengthFromComparison(current, previous, currentLength);
            previous = current;
            maxLength = std::max(maxLength, currentLength);
        }
        return maxLength;
    }
};
