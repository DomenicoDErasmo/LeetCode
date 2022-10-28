#include <iostream>
#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[i].size(); j++) {
                if (!isValidCell(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool isValidCell(std::vector<std::vector<char>>& board, size_t i, size_t j) {
        if (board[i][j] == '.') {return true;}
        if (isRowDuplicate(board, i, j)) {return false;}
        if (isColDuplicate(board, i, j)) {return false;}
        if (isBoxDuplicate(board, i, j)) {return false;}
        return true;
    }
    bool isRowDuplicate(std::vector<std::vector<char>>& board, size_t i, size_t j) {
        for (size_t x = 0; x < board[i].size(); x++) {
            if (board[i][x] == board[i][j] && (x != j)) {return true;}
        }
        return false;
    }
    bool isColDuplicate(std::vector<std::vector<char>>& board, size_t i, size_t j) {
        for (size_t y = 0; y < board.size(); y++) {
            if (board[y][j] == board[i][j] && (y != i)) {return true;}
        }
        return false;
    }
    bool isBoxDuplicate(std::vector<std::vector<char>>& board, size_t i, size_t j) {
        // using integer truncation
        size_t vertical_start = (i / 3) * 3, horizontal_start = (j / 3) * 3;
        for (size_t y = vertical_start; y < vertical_start + 3; y++) {
            for (size_t x = horizontal_start; x < horizontal_start + 3; x++) {
                if (board[y][x] == board[i][j] && ((y != i) || (x != j))) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}