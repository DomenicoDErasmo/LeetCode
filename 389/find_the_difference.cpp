#include <iostream>

class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        int s_frequency[26] = {0}, t_frequency[26] = {0};
        getFrequencies(s, s_frequency);
        getFrequencies(t, t_frequency);
        for (size_t i = 0; i < 26; i++) {
            if (s_frequency[i] != t_frequency[i]) {
               return (char)(i + 97);
            }
        }
        return 'a';
    }
private:
    void getFrequencies(const std::string& str, int frequency[26]) {
    for (size_t i = 0; i < str.length(); i++) {
        frequency[charToInt(str[i])]++;
        }
}
    int charToInt(char ch) {
        return (int)(ch) - 97;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}