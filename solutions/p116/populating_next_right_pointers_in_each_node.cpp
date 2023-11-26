#include <iostream>
#include <vector>
#include <queue>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    struct NodeLevel {
        Node* node;
        size_t level;
        
        NodeLevel(Node* node, size_t level): node(node), level(level) {}
    };
    
    Node* connect(Node* root) {
        if (!root) return root;
        std::vector<NodeLevel> bfs = BFS(root);
        int power_of_two = 4;
        for (size_t i = 1; i < bfs.size() - 1; i++) {
            // The 3rd, 7th, 15th, (2^n - 1)th nodes shouldn't have a next, so that's a -1
            // We store the 1st node at location 0, so to offset that's another -1
            if (i != power_of_two - 2) {
                bfs[i].node->next = bfs[i+1].node;
            } else {
                power_of_two *= 2;
            }
        }
        return root;
    }
private:
    std::vector<NodeLevel> BFS(Node* root) {
        std::vector<NodeLevel> bfs;
        
        std::queue<NodeLevel> queue;
        queue.push(NodeLevel(root, 1));
        while (!queue.empty()) {
            NodeLevel front = queue.front();
            if (front.node->left) queue.push(NodeLevel(front.node->left, front.level + 1));
            if (front.node->right) queue.push(NodeLevel(front.node->right, front.level + 1));
            bfs.push_back(front);
            queue.pop();
        }
        
        return bfs;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}