#include <iostream>
#include <vector>

class Solution {
public:
    void helper(int open, int close, int n, std::string current, std::vector<std::string>& result) {
        if (current.length() == n*2) {
            result.push_back(current);
            return;
        }
        if(open < n) {helper(open+1,close,n,current+"(", result);}
        if(close < open) {helper(open,close+1,n,current+")", result);}
    }
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        helper(0,0,n,"", result);
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}