#include <iostream>
#include <vector>

class Solution {
 public:
    void solve(std::vector<std::vector<char>>& board) {
        // iterate over left and right columns
        for (size_t i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') {
                DFS(board, i, 0);
            }
            if (board[i][board[0].size()-1] == 'O') {
                DFS(board, i, board[0].size()-1);        
            }
        }
        
        // iterate over top and bottom rows
        for (size_t j = 0; j < board[0].size(); j++) {
            if (board[0][j] == 'O') {
                DFS(board, 0, j);
            }
            if (board[board.size()-1][j] == 'O') {
                DFS(board, board.size()-1, j);        
            }
        }
        
        boardSweep(board, 'O', 'X');
        boardSweep(board, '#', 'O');
    }
 private:
    void boardSweep(std::vector<std::vector<char>>& board, char from, char to) {
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                if (board[i][j] == from) {
                    board[i][j] = to;
                }
            }
        }
    }
    
    void DFS(std::vector<std::vector<char>>& board, int i, int j) {
        if (i < 0 || i > board.size()-1 || j < 0 || j > board[0].size()-1 || board[i][j] != 'O') {return;}
        
        // sentinel character to show we reached this O via DFS
        board[i][j] = '#';
        DFS(board, i-1, j);
        DFS(board, i+1, j);
        DFS(board, i, j-1);
        DFS(board, i, j+1);
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}
