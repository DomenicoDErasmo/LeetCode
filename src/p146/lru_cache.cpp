#include <unordered_map>
#include <vector>

class LRUCache {
   public:
    LRUCache(int capacity) : cache({}), LRU({}), capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        std::vector<int> newLRU;
        newLRU.push_back(key);
        int foundIndex = findInLRU(key);
        newLRU.insert(newLRU.end(), LRU.begin(), LRU.begin() + foundIndex);
        newLRU.insert(newLRU.end(), LRU.begin() + foundIndex + 1, LRU.end());
        LRU = newLRU;

        return cache[key];
    }

    void put(int key, int value) {
        int maybeFound = findInLRU(key);

        if (cache.find(key) != cache.end()) {
            cache.erase(key);
            cache.insert({key, value});

            LRU.erase(LRU.begin() + maybeFound);
            LRU.insert(LRU.begin(), key);
            return;
        }

        if (LRU.size() < capacity) {
            LRU.insert(LRU.begin(), key);
            cache.insert({key, value});
            return;
        }

        cache.erase(LRU.back());
        if (maybeFound == -1) {
            LRU.insert(LRU.begin(), key);
            LRU.pop_back();
        }

        cache.insert({key, value});
    }

   private:
    std::unordered_map<int, int> cache;
    std::vector<int> LRU;
    int capacity;

    int findInLRU(int key) {
        for (int i = 0; i < LRU.size(); i++) {
            if (LRU[i] == key) {
                return i;
            }
        }
        return -1;
    }
};
