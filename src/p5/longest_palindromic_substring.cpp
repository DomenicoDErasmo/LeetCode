#include <iostream>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        size_t length = s.length();
        
        // init the dp array
        bool** dp = new bool*[length];
        for (size_t i = 0; i < length; i++) {
            dp[i] = new bool[length];
        }
        
        // base case: dp[i][i] is one character wide so it must be a palindrome
        for (size_t i = 0; i < length; i++) {
            dp[i][i] = true;
        }
        
        // base case: dp[i][i+1] is two characters wide so it must be whether s[i] == s[i+1]
        for (size_t i = 0; i < length - 1; i++) {
            dp[i][i+1] = (s[i] == s[i+1]);
        }
        
        // general case: dp[i][j] = dp[i+1][j-1] && (s[i] == s[j])
        // we can only have a palindrome if the first and last letters are equal and if by removing those letters, you still have a palindrome
        int i = 0, j = 2, j_temp = j;
        while (j_temp < length) {
            while (i < length && j < length) {
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                
                // move up diagonally, as we need to know the north-west cell to proceed
                i++;
                j++;
            }
            j_temp++;
            i = 0;
            j = j_temp;
            
        }
        
        // scan through the array for the greatest difference between i and j
        int start = 0, end = 0, largest = 1;
        for (size_t i = 0; i < length; i++) {
            for (size_t j = i; j < length; j++) {
                if (dp[i][j] && (j - i + 1) > largest) {
                    largest = j - i + 1;
                    start = i;
                    end = j;
                }
            }
        }
        
        // cleanup after our new!
        delete[] dp;
        return s.substr(start, largest);
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}