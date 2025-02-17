#include <iostream>
#include <queue>
#include <vector>

class MaxHeap {
   public:
    MaxHeap() : heap({-1}) {}

    int size() { return heap.size() - 1; }

    bool empty() { return size() == 0; }

    void heapify(std::vector<int> array) {
        heap = array;
        heap.push_back(heap[0]);

        int current = (heap.size() - 1) / 2;
        while (current > 0) {
            int i = current;
            while (left(i) < heap.size()) {
                if (right(i) < heap.size() && heap[right(i)] > heap[left(i)] &&
                    heap[right(i)] > heap[i]) {
                    std::swap(heap[i], heap[right(i)]);
                    i = right(i);
                } else if (heap[left(i)] > heap[i]) {
                    std::swap(heap[i], heap[left(i)]);
                    i = left(i);
                } else {
                    break;
                }
            }
            current--;
        }
    }

    // for debugging
    std::string toString() {
        std::string result;
        result += "Heap: ";
        for (int i = 1; i < heap.size(); i++) {
            result += std::to_string(heap[i]);
            result += ", ";
        }
        return result;
    }

    int max() { return heap[1]; }

    void push(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i > 1) {
            if (heap[i] > heap[parent(i)]) {
                std::swap(heap[i], heap[parent(i)]);
            }
            i = parent(i);
        }
    }

    void pop() {
        if (heap.size() < 1) {
            return;
        }

        heap[1] = heap.back();
        heap.pop_back();

        int i = 1;
        while (left(i) < heap.size()) {
            if (right(i) < heap.size() && heap[right(i)] > heap[left(i)] &&
                heap[right(i)] > heap[i]) {
                std::swap(heap[i], heap[right(i)]);
                i = right(i);
            } else if (heap[left(i)] > heap[i]) {
                std::swap(heap[i], heap[left(i)]);
                i = left(i);
            } else {
                return;
            }
        }
    }

   private:
    std::vector<int> heap;

    int left(int i) { return 2 * i; }

    int right(int i) { return 2 * i + 1; }

    int parent(int i) { return i / 2; }
};

class Solution {
   public:
    int lastStoneWeight(std::vector<int>& stones) {
        MaxHeap heap;
        heap.heapify(stones);
        while (heap.size() >= 2) {
            int largest = heap.max();
            heap.pop();
            int secondLargest = heap.max();
            heap.pop();

            if (largest != secondLargest) {
                heap.push(largest - secondLargest);
            }
        }
        return heap.empty() ? 0 : heap.max();
    }
};
