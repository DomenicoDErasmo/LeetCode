#include <iostream>
#include <map>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        std::map<std::tuple<size_t, size_t, size_t>, bool> cache;
        return helper(s1, 0, s2, 0, s3, 0, cache);
    }
private:
    bool helper(const std::string& s1, const size_t& l1, const std::string& s2, const size_t& l2, const std::string& s3, const size_t& l3, std::map<std::tuple<size_t, size_t, size_t>, bool>& cache) {
        if (l1 == s1.length() && l2 == s2.length() && l3 == s3.length()) return true;
        std::tuple<size_t, size_t, size_t> args(l1, l2, l3);
        
        if (cache.find(args) != cache.end()) return cache[args];
        
        bool answer = false;
        if (l1 < s1.length() && s1[l1] == s3[l3])
            answer = answer || helper(s1, l1 + 1, s2, l2, s3, l3 + 1, cache);
        if (l2 < s2.length() && s2[l2] == s3[l3])
            answer = answer || helper(s1, l1, s2, l2 + 1, s3, l3 + 1, cache);
        return cache[args] = answer;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}