#include <iostream>
#include <vector>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[i].size(); j++) {
                if (helper(board, word, i, j)) return true;
            }
        }
        return false;
    }
private:
    bool helper(std::vector<std::vector<char>>& board, std::string word, int i, int j) {
        if (word.size() == 0) return true;
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[0]) return false;
        char temp = board[i][j];
        board[i][j] = '*';
        std::string new_word = word.substr(1);
        bool result = helper(board, new_word, i - 1, j) || helper(board, new_word, i + 1, j) || helper(board, new_word, i, j - 1) || helper(board, new_word, i, j + 1);
        board[i][j] = temp;
        
        return result;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}