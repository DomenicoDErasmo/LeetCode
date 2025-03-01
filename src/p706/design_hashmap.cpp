#include <vector>

const int DEFAULT_CAPACITY = 2;

struct Pair {
    int key, value;
    Pair(int key, int value) : key(key), value(value) {}
};

class MyHashMap {
   public:
    MyHashMap()
        : size(0),
          capacity(DEFAULT_CAPACITY),
          vals(std::vector<std::vector<Pair>>(DEFAULT_CAPACITY,
                                              std::vector<Pair>())) {}

    void put(int key, int value) {
        int index = hash(key);

        for (std::vector<Pair>::iterator pair = vals[index].begin(); pair != vals[index].end(); pair++) {
            if (pair->key == key) {
                pair->value = value;
                return;
            }
        }

        vals[index].push_back(Pair(key, value));
        size++;
        if (size >= capacity * 0.5) {
            resize();
        }
    }

    int get(int key) {
        int index = hash(key);

        for (Pair pair : vals[index]) {
            if (pair.key == key) {
                return pair.value;
            }
        }

        return -1;
    }

    void remove(int key) {
        int index = hash(key);

        for (int i = 0; i < vals[index].size(); i++) {
            if (vals[index][i].key == key) {
                vals[index].erase(vals[index].begin() + i);
                size--;
                return;
            }
        }
    }

   private:
    int size, capacity;
    std::vector<std::vector<Pair>> vals;

    int hash(int key) { return key % capacity; }

    void resize() {
        std::vector<std::vector<Pair>> oldVals = vals;
        capacity *= 2;
        vals = std::vector<std::vector<Pair>>(capacity, std::vector<Pair>());
        for (std::vector<Pair> list : oldVals) {
            for (Pair pair : list) {
                put(pair.key, pair.value);
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */