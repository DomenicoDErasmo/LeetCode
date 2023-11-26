#include <iostream>

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        int result = 0;
        size_t place = 1;
        for (int i = columnTitle.length() - 1; i >= 0; i--) {
            result += (((int)columnTitle[i] - 64) * place);
            place *= 26;
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}