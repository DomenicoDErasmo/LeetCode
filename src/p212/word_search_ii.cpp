#include <string>         // string
#include <unordered_map>  // unordered_map
#include <unordered_set>  // unordered_set
#include <vector>         // vector

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isWord;

    TrieNode() : children({}), isWord(false) {}
};

TrieNode* get(TrieNode* root, std::string word) {
    TrieNode* temp = root;
    for (char ch : word) {
        if (temp->children.find(ch) == temp->children.end()) {
            return nullptr;
        }
        temp = temp->children[ch];
    }
    return temp;
}

void insert(TrieNode* root, std::string word) {
    TrieNode* temp = root;
    for (char ch : word) {
        if (temp->children.find(ch) == temp->children.end()) {
            temp->children.insert({ch, new TrieNode()});
        }
        temp = temp->children[ch];
    }
    temp->isWord = true;
}

bool search(TrieNode* root, std::string word) {
    TrieNode* node = get(root, word);
    return node && node->isWord;
}

template <typename T>
using Grid = std::vector<std::vector<T>>;

template <typename T>
using Row = std::vector<T>;

using Direction = std::pair<int, int>;
const std::vector<Direction> DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

template <typename T>
bool outOfBounds(const Grid<T>& grid, int i, int j) {
    return i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size();
}

class Solution {
   public:
    Row<std::string> findWords(Grid<char>& board, Row<std::string>& words) {
        Grid<bool> visited(board.size(), Row<bool>(board[0].size(), false));
        TrieNode* root = new TrieNode();
        for (std::string word : words) {
            insert(root, word);
        }

        std::unordered_set<std::string> result;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                std::string current;
                DFS(root, board, i, j, current, visited, result);
            }
        }
        return std::vector<std::string>(result.begin(), result.end());
    }

   private:
    void DFS(TrieNode* trie, const Grid<char>& board, int i, int j,
             std::string& word, Grid<bool>& visited,
             std::unordered_set<std::string>& result) {
        if (outOfBounds(board, i, j) || visited[i][j] ||
            trie->children.find(board[i][j]) == trie->children.end()) {
            return;
        }

        visited[i][j] = true;
        word += board[i][j];
        
        trie = trie->children[board[i][j]];

        if (trie->isWord) {
            result.insert(word);
        }

        for (Direction direction : DIRECTIONS) {
            DFS(trie, board, i + direction.first, j + direction.second, word,
                visited, result);
        }

        word.pop_back();
        visited[i][j] = false;
    }
};
