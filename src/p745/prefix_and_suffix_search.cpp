#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* links[26];
    set<int, greater<int>> s;
    Node() {
        for (int i = 0; i < 26; i++) links[i] = NULL;
    }
    bool contains(char c) { return links[c - 'a'] != NULL; }
    void put(char c, Node* new_node, int index) { links[c - 'a'] = new_node; }
    Node* get(char c) { return links[c - 'a']; }
};
class Trie {
   private:
    Node* root;

   public:
    Trie() { root = new Node(); }
    void insert(string word, int type, int index) {
        Node* node = root;
        if (type == 0) {
            for (int i = 0; i < word.size(); i++) {
                if (!node->contains(word[i])) {
                    node->put(word[i], new Node(), index);
                }
                node = node->get(word[i]);
                node->s.insert(index);
            }
        } else {
            for (int i = word.size() - 1; i >= 0; i--) {
                if (!node->contains(word[i])) {
                    node->put(word[i], new Node(), index);
                }
                node = node->get(word[i]);
                node->s.insert(index);
            }
        }
    }
    Node* get_root() { return root; }
};
class WordFilter {
   public:
    Trie t1, t2;
    WordFilter(vector<string>& words) {
        int index = 0;
        for (auto& i : words) {
            t1.insert(i, 0, index);
            t2.insert(i, 1, index);
            index++;
        }
    }

    int f(string pref, string suff) {
        Node* node1 = t1.get_root();
        Node* node2 = t2.get_root();
        for (auto i : pref) {
            if (node1->contains(i)) {
                node1 = node1->get(i);
            } else
                return -1;
        }
        for (int i = suff.size() - 1; i >= 0; i--) {
            if (node2->contains(suff[i])) {
                node2 = node2->get(suff[i]);
            } else
                return -1;
        }
        auto& s1 = node1->s;
        auto& s2 = node2->s;

        auto it1 = s1.begin();
        auto it2 = s2.begin();

        while (it1 != s1.end() && it2 != s2.end()) {
            if (*it1 == *it2) return *it1;
            if (*it1 > *it2)
                ++it1;
            else
                ++it2;
        }
        return -1;
    }
};
