#include<iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // remove negative signs, reintroduce at the end
        long cleaned_dividend = customAbs(dividend);
        long cleaned_divisor = customAbs(divisor);
        
        long result = getRawResult(cleaned_dividend, cleaned_divisor);
        bool is_negative = ((dividend < 0 && divisor > 0) 
                            || (dividend > 0 && divisor < 0));
        result = parseResult(result, is_negative);
        
        return result;
    }
private:
    long getRawResult(long& dividend, long& divisor) {
        if (divisor == 1) {return dividend;}
        long result = 0, partial_sum = 0;
        while (true) {
            if (partial_sum + divisor <= dividend) {
                partial_sum += divisor;
                result++;
            } else {
                break;
            }
        }
        
        return result;
    }
    
    int parseResult(long& raw_result, bool& is_negative) {
        
        // account for sign from is_negative
        if (is_negative) {raw_result *= -1;}
        
        // clamp result to int bounds
        if (raw_result < INT_MIN) {raw_result = INT_MIN;}
        if (raw_result > INT_MAX) {raw_result = INT_MAX;}
        
        return raw_result;
    }
    
    long customAbs(long n) {
        return n < 0 ? (n * -1) : n;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}