#include <algorithm>      // sort
#include <string>         // string
#include <unordered_map>  // unordered_map
#include <vector>         // vector

class UnionFind {
   public:
    UnionFind(int n) : parent(n, 0), rank(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool merge(int n1, int n2) {
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2) {
            return false;
        }

        if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }

   private:
    std::vector<int> parent, rank;
};

class Solution {
   public:
    std::vector<std::vector<std::string>> accountsMerge(
        std::vector<std::vector<std::string>>& accounts) {
        UnionFind unionFind(accounts.size());
        std::unordered_map<std::string, int> emailToAccount;

        // build union-find structure
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                const std::string& email = accounts[i][j];
                if (emailToAccount.count(email)) {
                    unionFind.merge(i, emailToAccount[email]);
                } else {
                    emailToAccount[email] = i;
                }
            }
        }

        // group emails by leader account
        std::unordered_map<int, std::vector<std::string>> emailGroup;
        for (const auto& [email, accountId] : emailToAccount) {
            int parent = unionFind.find(accountId);
            emailGroup[parent].push_back(email);
        }

        // build result
        std::vector<std::vector<std::string>> result;
        for (auto& [accountId, emails] : emailGroup) {
            std::sort(emails.begin(), emails.end());
            std::vector<std::string> merged;

            // this is the account name
            merged.push_back(accounts[accountId][0]);

            // insert sorted emails
            merged.insert(merged.end(), emails.begin(), emails.end());

            // add to result
            result.push_back(merged);
        }

        return result;
    }
};
