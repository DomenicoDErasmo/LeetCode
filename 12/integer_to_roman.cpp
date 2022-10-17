#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::string intToRoman(int num) {
        std::unordered_map<cutoffs, std::string> conversion = {
            {M, "M"},
            {CM, "CM"},
            {D, "D"},
            {CD, "CD"},
            {C, "C"},
            {XC, "XC"},
            {L, "L"},
            {XL, "XL"},
            {X, "X"},
            {IX, "IX"},
            {V, "V"},
            {IV, "IV"},
            {I, "I"}
        };
        
        std::string result;
        while (num) {
            cutoffs cutoff = intToCutoff(num);
            result += conversion[cutoff];
            num -= cutoff;
        }
        
        return result;
    }
private:
    enum cutoffs {
        M = 1000,
        CM = 900,
        D = 500,
        CD = 400,
        C = 100,
        XC = 90,
        L = 50,
        XL = 40,
        X = 10,
        IX = 9,
        V = 5,
        IV = 4,
        I = 1,
    };
    // assumes num >= 1
    cutoffs intToCutoff(int num) {
        if (num >= 1000) {return M;}
        if (num >= 900) {return CM;}
        if (num >= 500) {return D;}
        if (num >= 400) {return CD;}
        if (num >= 100) {return C;}
        if (num >= 90) {return XC;}
        if (num >= 50) {return L;}
        if (num >= 40) {return XL;}
        if (num >= 10) {return X;}
        if (num >= 9) {return IX;}
        if (num >= 5) {return V;}
        if (num >= 4) {return IV;}
        return I;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}