#include <iostream>
#include <unordered_map>
#include <vector>

class Node {
    public:
        int val;
        std::vector<Node*> neighbors;
        Node(): val(0), neighbors(std::vector<Node*>()) {}
        Node(int _val): val(_val), neighbors(std::vector<Node*>()) {}
        Node(
            int _val, 
            std::vector<Node*> _neighbors): val(_val), neighbors(_neighbors) {}
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {return nullptr;}
        std::unordered_map<Node*, Node*> made;
        return cloneGraphHelper(node, made);
    }
private:
    Node* cloneGraphHelper(Node* node, std::unordered_map<Node*, Node*>& made) {
        Node* head = new Node(node->val);
        made[node] = head;
        for (
                std::vector<Node*>::iterator it = node->neighbors.begin(); 
                it != node->neighbors.end(); 
                it++) {
            if (made.count(*it)) {head->neighbors.push_back(made[*it]);}
            else {head->neighbors.push_back(cloneGraphHelper(*it, made));}
        }
        return head;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}