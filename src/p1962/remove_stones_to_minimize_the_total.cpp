#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

class Solution {
public:
    int minStoneSum(std::vector<int>& A, int k) {
        std::priority_queue<int> pq(A.begin(), A.end());
        int res = std::accumulate(A.begin(), A.end(), 0);
        while (k--) {
            int a = pq.top();
            pq.pop();
            pq.push(a - a / 2);
            res -= a / 2;
        }
        return res;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}
