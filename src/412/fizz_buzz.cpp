#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> result;
        for (size_t i = 1; i <= n; i++) {
            std::string next_result;
            if (i % 3 && i % 5) {next_result = std::to_string(i);}
            if (!(i % 3)) {next_result += "Fizz";}
            if (!(i % 5)) {next_result += "Buzz";}
            result.push_back(next_result);
        }
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}