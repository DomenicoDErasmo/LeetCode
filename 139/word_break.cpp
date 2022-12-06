#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> words(wordDict.begin(), wordDict.end());
        std::vector<int> helper(s.size()+1, 0);
        helper[0] = 1;
        for (int i = 0; i < helper.size(); i++) {
            for (int j = 0; j < i && !helper[i]; j++) {
                // if we could make a string of the previous length 
                // AND we can find the current substring in the set
                if (helper[j] && words.count(s.substr(j, i-j))) {
                    helper[i] = 1;
                }
            }
        }
        return helper[s.size()];
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}