#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {return false;}
        
        std::unordered_map<char, int> s_frequency, t_frequency;
        for (size_t i = 0; i < s.length(); i++) {
            if (s_frequency.find(s[i]) == s_frequency.end()) {s_frequency.insert({s[i], 1});}
            else {s_frequency[s[i]]++;}
        }
        
        for (size_t i = 0; i < t.length(); i++) {
            if (t_frequency.find(t[i]) == t_frequency.end()) {t_frequency.insert({t[i], 1});}
            else {t_frequency[t[i]]++;}
        }
        
        return s_frequency == t_frequency;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}