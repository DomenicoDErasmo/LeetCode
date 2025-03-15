#include <string>         // string
#include <unordered_map>  // unordered_map

struct TrieNode {
    std::unordered_map<char, TrieNode *> children;
    bool isWord;

    TrieNode() : children({}), isWord(false) {}
};

class Trie {
   public:
    Trie() : root(new TrieNode()) {}

    void insert(std::string word) {
        TrieNode *temp = root;
        for (char ch : word) {
            if (temp->children.find(ch) == temp->children.end()) {
                temp->children.insert({ch, new TrieNode()});
            }
            temp = temp->children[ch];
        }
        temp->isWord = true;
    }

    bool search(std::string word) {
        TrieNode *node = get(word);
        return node && node->isWord;
    }

    bool startsWith(std::string prefix) { return get(prefix); }

   private:
    TrieNode *root;

    TrieNode *get(std::string word) {
        TrieNode *temp = root;
        for (char ch : word) {
            if (temp->children.find(ch) == temp->children.end()) {
                return nullptr;
            }
            temp = temp->children[ch];
        }
        return temp;
    }
};
