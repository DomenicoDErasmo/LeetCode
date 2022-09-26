#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> ransom_frequency, magazine_frequency;
        populateFrequency(ransom_frequency, ransomNote);
        populateFrequency(magazine_frequency, magazine);
        for (std::unordered_map<char, int>::iterator iter = ransom_frequency.begin(); iter != ransom_frequency.end(); iter++) {
            char key = iter->first;
            if (magazine_frequency.find(key) == magazine_frequency.end() 
                || magazine_frequency[key] < ransom_frequency[key]) {
                return false;
            }
        }
        return true;
    }
private:
    void populateFrequency(std::unordered_map<char, int>& frequency, const std::string& str) {
        for (size_t i = 0; i < str.length(); i++) {
            if (frequency.find(str[i]) == frequency.end()) {
                frequency.insert({str[i], 1});
            } else {
                frequency[str[i]]++;
            }
        }
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}