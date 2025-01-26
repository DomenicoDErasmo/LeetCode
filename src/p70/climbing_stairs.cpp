#include <unordered_map>
#include <vector>

class Solution
{
public:
    int climbStairs(int n)
    {
        return climbStairsTabulationSpaceOptimized(n);
    }

    int climbStairsRecursive(int n)
    {
        if (0 <= n && n <= 2)
        {
            return n;
        }

        return climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2);
    }

    int climbStairsMemoization(int n)
    {
        std::unordered_map<int, int> cache;
        // base case
        for (int i = 0; i <= 2; i++)
        {
            cache.insert({i, i});
        }

        // general case
        return climbStairsMemoizationHelper(n, cache);
    }

    int climbStairsMemoizationHelper(int n, std::unordered_map<int, int> &cache)
    {
        if (cache.find(n) != cache.end())
        {
            return cache[n];
        }

        int result = climbStairsMemoizationHelper(n - 2, cache) + climbStairsMemoizationHelper(n - 1, cache);
        cache.insert({n, result});

        return result;
    }

    int climbStairsTabulation(int n)
    {
        int *subproblems = new int[n + 1];

        // base case
        if (n <= 2)
        {
            return n;
        }
        for (int i = 0; i <= 2; i++)
        {
            subproblems[i] = i;
        }

        // general case
        for (int i = 3; i <= n; i++)
        {
            subproblems[i] = subproblems[i - 1] + subproblems[i - 2];
        }

        int result = subproblems[n];
        delete[] subproblems;
        return result;
    }

    int climbStairsTabulationSpaceOptimized(int n) {
        // base case
        if (n <= 2) {
            return n;
        }

        int two_ago = 1, one_ago = 2, result = 0;
        
        // general case
        for (int i = 3; i <= n; i++) {
            result = one_ago + two_ago;
            two_ago = one_ago;
            one_ago = result;
        }

        return result;
    }
};
