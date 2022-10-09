#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::string>& words) {
        std::set<char> first_row = {'q', 'Q', 'w', 'W', 'e', 'E', 'r', 'R', 't', 'T', 'y', 'Y', 'u', 'U', 'i', 'I', 'o', 'O', 'p', 'P'};
        std::set<char> second_row = {'a', 'A', 's', 'S', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j', 'J', 'k', 'K', 'l', 'L'};
        std::set<char> third_row = {'z', 'Z', 'x', 'X', 'c', 'C', 'v', 'V', 'b', 'B', 'n', 'N', 'm', 'M'};
        
        std::vector<std::string> result;
        
        for (size_t i = 0; i < words.size(); i++) {
            // Choose row to search based on first letter
            char first_letter = words[i][0];
            std::set<char> row;
            if (first_row.find(first_letter) != first_row.end()) {
                row = first_row;
            } else if (second_row.find(first_letter) != second_row.end()) {
                row = second_row;
            } else {
                row = third_row;
            }
            
            bool found = true;
            for (size_t j = 1; j < words[i].length(); j++) {
                if (row.find(words[i][j]) == row.end()) {
                    found = false;
                    break;
                }
            }
            
            if (found) {
                result.push_back(words[i]);
            }
            
        }
        
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}