#include <unordered_set>  // unordered_set
#include <vector>         // vector

class UnionFind {
   public:
    UnionFind(int n) : parent(n, 0), rank(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (node != parent[node]) {
            node = find(parent[node]);
        }
        return node;
    }

    bool merge(int node1, int node2) {
        int parent1 = find(node1), parent2 = find(node2);
        if (parent1 == parent2) {
            return false;
        }

        if (rank[parent1] > rank[parent2]) {
            parent[parent2] = parent1;
            rank[parent1] += rank[parent2];
        } else {
            parent[parent1] = parent2;
            rank[parent2] += rank[parent1];
        }

        return true;
    }

   private:
    std::vector<int> parent, rank;
};

class Solution {
   public:
    int countComponents(int n, std::vector<std::vector<int>>& edges) {
        UnionFind uf(n);

        int result = n;

        // merge all edges
        for (std::vector<int> edge : edges) {
            if (uf.merge(edge.front(), edge.back())) {
                result--;
            }
        }

        return result;
    }
};
