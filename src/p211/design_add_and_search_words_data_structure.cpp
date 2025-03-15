#include <string>         // string
#include <unordered_map>  // unordered_map

struct TrieNode {
    // alternate: use vector and use [ch - 'a'] as "hashing"
    std::unordered_map<char, TrieNode *> children;
    bool isWord;
    TrieNode() : children({}), isWord(false) {}
};

class WordDictionary {
   public:
    WordDictionary() : root(new TrieNode()) {}

    void addWord(std::string word) {
        TrieNode *temp = root;
        for (char ch : word) {
            if (temp->children.find(ch) == temp->children.end()) {
                temp->children.insert({ch, new TrieNode()});
            }
            temp = temp->children[ch];
        }
        temp->isWord = true;
    }

    bool search(std::string word) { return searchHelper(root, word); }

   private:
    TrieNode *root;

    bool searchHelper(TrieNode *start, std::string word) {
        TrieNode *temp = start;
        for (int i = 0; i < word.size(); i++) {

            char ch = word[i];

            if (ch == '.') {
                std::string subProblem = word.substr(i + 1);
                for (auto key : temp->children) {
                    if (searchHelper(key.second, subProblem)) {
                        return true;
                    }
                }
                return false;
            }

            if (temp->children.find(ch) == temp->children.end()) {
                return false;
            }
            temp = temp->children[ch];
        }
        return temp->isWord;
    }
};
