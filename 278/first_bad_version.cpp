#include <iostream>

// Dummy stub so this compiles, although the test cases would probably implement it this way
bool isBadVersion(int i) {
    return i;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n, mid = left + (right - left)/2;
        while(left <= right) {
            if (!isBadVersion(mid - 1) && isBadVersion(mid)) {return mid;}
            else if (isBadVersion(mid)) {right = mid - 1;} 
            else {left = mid + 1;}
            mid = left + (right - left)/2;
        }
        return mid;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}