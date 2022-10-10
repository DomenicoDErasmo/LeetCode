#include <iostream>
#include <string>

class Solution {
public:
    std::string convertToBase7(int num) {        
        std::string result;
        
        // handle case of num being negative
        if (num < 0) {
            result += '-';
            num *= -1;
        }
        
        // find largest place
        int largest_power = 0;
        while (pow(7, largest_power + 1) <= num) {
            largest_power++;
        }
        
        while (largest_power >= 0) {
            int place_val = num / pow(7, largest_power);
            result += std::to_string(place_val);
            num -= place_val * pow(7, largest_power);
            largest_power--;
        }
        
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}