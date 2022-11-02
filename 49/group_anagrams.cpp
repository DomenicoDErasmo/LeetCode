#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        if (strs.size() == 0) {return {{strs[0]}};}
        std::vector<std::vector<std::string>> result;
        std::unordered_map<std::string, std::vector<std::string>> sorted;
        
        for (size_t i = 0; i < strs.size(); i++) {
            std::string str = strs[i];
            std::sort(str.begin(), str.end());
            sorted[str].push_back(strs[i]);
        }
        
        for (std::unordered_map<std::string, std::vector<std::string>>::iterator it = sorted.begin(); it != sorted.end(); it++) {
            result.push_back(it->second);
        }
        
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}