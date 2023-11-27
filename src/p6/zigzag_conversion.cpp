#include <iostream>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) {return s;}
        
        std::string result;
        
        char** grid;
        buildGrid(grid, s, numRows);
        
        for (size_t i = 0; i < numRows; i++) {
            for (size_t j = 0; j < s.length(); j++) {
                if (grid[i][j] != '0') {
                    result += grid[i][j];
                }
            }
        }
        
        delete[] grid;
        return result;
    }
private:
    void buildGrid(char**& grid, const std::string& s, int numRows) {
        grid = new char*[numRows];
        for (size_t i = 0; i < numRows; i++) {
            // too complicated to compact, let's just make the largest array that we know this will fit in
            grid[i] = new char[s.length()];
            // '0' isn't a possible character in s, so let's use it for empty space
            memset(grid[i], '0', sizeof(char) * s.length());
        }
        
        // add the letters in zig-zag format
        int pos = 0, i = 0, j = 0;
        bool diagonal = false;
        while (pos < s.length()) {
            grid[i][j] = s[pos];
            if (diagonal) {
                if (i == 0) {
                    diagonal = false;
                    i++;
                } else {
                    i--;
                    j++;
                }
            } else {
                if (i == numRows - 1) {
                    diagonal = true;
                    i--;
                    j++;
                } else {
                    i++;
                }
            }
            
            pos++;
        }
    }
    void printGrid(char** grid, int numRows, int length) {
        for (size_t i = 0; i < numRows; i++) {
            for (size_t j = 0; j < length; j++) {
                std::cout << grid[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}