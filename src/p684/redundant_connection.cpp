#include <unordered_map>  // unordered_map
#include <vector>         // vector

class UnionFind {
   public:
    UnionFind(int n) : parent(), rank() {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[1] = 0;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool combine(int n1, int n2) {
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2) {
            return false;
        }

        if (rank[p1] > rank[p2]) {
            parent[p2] = parent[p1];
        } else if (rank[p1] < rank[p2]) {
            parent[p1] = parent[p2];
        } else {
            parent[p1] = parent[p2];
            rank[p2]++;
        }
        return true;
    }

   private:
    std::unordered_map<int, int> parent, rank;
};

class Solution {
   public:
    std::vector<int> findRedundantConnection(
        std::vector<std::vector<int>>& edges) {
        UnionFind unionFind(edges.size());
        std::vector<int> redundant;

        for (std::vector<int> edge : edges) {
            if (!unionFind.combine(edge.front(), edge.back())) {
                redundant = edge;
            }
        }

        return redundant;
    }
};
