#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        if (s.length() < 10) {return std::vector<std::string>();}

        std::unordered_set<std::string> uniques, repeated;

        for (int i = 0; i < s.length() - 9; i++) {
            std::string candidate = s.substr(i, 10);
            if (uniques.find(candidate) == uniques.end()) {
                uniques.insert(candidate);
            } else {
                repeated.insert(candidate);
            }
        }

        std::vector<std::string> result;
        for (
                std::unordered_set<std::string>::iterator it = repeated.begin(); 
                it != repeated.end(); 
                it++) {
            result.push_back(*it);
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}
