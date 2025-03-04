#include <unordered_map>
#include <vector>

class Node {
   public:
    int val;
    std::vector<Node*> neighbors;
    Node() : val(0), neighbors({}) {}
    Node(int val) : val(val), neighbors({}) {}
    Node(int val, std::vector<Node*> neighbors)
        : val(val), neighbors(neighbors) {}
};

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return node;
        }

        std::unordered_map<int, Node*> clonedNodes;
        return helper(node, clonedNodes);
    }

   private:
    Node* helper(Node* node, std::unordered_map<int, Node*>& clonedNodes) {
        Node* result = clonedNodes.find(node->val) != clonedNodes.end()
                           ? clonedNodes[node->val]
                           : new Node(node->val);
        clonedNodes.insert({node->val, result});
        for (Node* neighbor : node->neighbors) {
            Node* clonedNeighbor =
                clonedNodes.find(neighbor->val) != clonedNodes.end()
                    ? clonedNodes[neighbor->val]
                    : helper(neighbor, clonedNodes);
            result->neighbors.push_back(clonedNeighbor);
        }
        return result;
    }
};
