#include <vector> // vector

class Solution {
    public:
        std::vector<int> countBits(int n) {
            std::vector<int> result;
            for (int i = 0; i <= n; i++) {
                result.push_back(numBits(i));
            }
            return result;
        }

    private:
        int numBits(int n) {
            int result = 0;
            while (n > 0) {
                result += (n & 1);
                n >>= 1;
            }
            return result;
        }
};