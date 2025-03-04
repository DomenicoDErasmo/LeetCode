#include <unordered_map>
#include <unordered_set>
#include <vector>

using EdgeList = std::vector<std::vector<int>>;
using Graph = std::unordered_map<int, std::vector<int>>;

class Solution {
   public:
    bool canFinish(int numCourses, EdgeList& prerequisites) {
        if (prerequisites.empty()) {
            return true;
        }

        // convert edge list into adjacency list
        Graph requirements = fromPrerequisites(prerequisites);
        std::unordered_set<int> visited;
        std::unordered_map<int, bool> cache;

        // for isolated components
        for (int i = 0; i < numCourses; i++) {
            if (!isDAG(requirements, visited, i, cache)) {
                return false;
            }
        }
        return true;
    }

   private:
    Graph fromPrerequisites(const EdgeList& prerequisites) {
        Graph requirements;
        for (const std::vector<int>& prerequisite : prerequisites) {
            int source = prerequisite.front(),
                destination = prerequisite.back();
            if (requirements.find(source) == requirements.end()) {
                requirements.insert({source, {destination}});
            } else {
                requirements[source].push_back(destination);
            }
        }
        return requirements;
    }

    bool isDAG(Graph& requirements, std::unordered_set<int>& visited,
               int current, std::unordered_map<int, bool>& cache) {
        if (cache.find(current) != cache.end()){ 
            return cache[current];
        }

        if (visited.find(current) != visited.end()) {
            cache.insert({current, false});
            return false;
        }

        visited.insert(current);
        for (int neighbor : requirements[current]) {
            if (!isDAG(requirements, visited, neighbor, cache)) {
                cache.insert({current, false});
                return false;
            }
        }
        visited.erase(current);
        cache.insert({current, true});
        return true;
    }
};
