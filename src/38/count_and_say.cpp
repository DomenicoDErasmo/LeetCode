#include <iostream>
#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        if (n == 1) {return "1";}
        std::string result = "";
        std::string base_string = countAndSay(n-1);
        char current = base_string[0];
        size_t num_current = 1;
        for (size_t i = 1; i < base_string.length(); i++) {
            if (base_string[i] == current) {
                num_current++;
            } else {
                result += (std::to_string(num_current) + current);
                current = base_string[i];
                num_current = 1;
            }
        }
        result += (std::to_string(num_current) + current);
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}