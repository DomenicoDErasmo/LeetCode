#include <iostream>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> cipher;
        std::unordered_set<char> taken_destinations;
        
        for(size_t i = 0; i < t.size(); i++) {
            if (cipher.find(s[i]) == cipher.end()) {
                if (taken_destinations.find(t[i]) != taken_destinations.end()) {return false;
                                                                               }
                cipher.insert({s[i], t[i]});
                taken_destinations.insert(t[i]);
            } else if (cipher[s[i]] != t[i]) {return false;}
        }
        return true;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}