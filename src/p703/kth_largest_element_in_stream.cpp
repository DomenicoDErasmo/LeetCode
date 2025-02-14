#include <vector>

class KthLargest {
   public:
    KthLargest(int k, std::vector<int>& nums) {
        k = k;
        maxHeap = {-1};

        for (int num : nums) {
            push(num);
        }
    }

    int add(int val) {
        push(val);
        std::vector<int> dummyHeap = maxHeap, largestScores;
        for (int i = 0; i < myK; i++) {
            largestScores.push_back(pop(dummyHeap));
        }

        return largestScores.back();
    }

   private:
    int myK;
    std::vector<int> maxHeap;

    int left(int i) { return 2 * i; }

    int right(int i) { return 2 * i + 1; }

    int parent(int i) { return i / 2; }

    void push(int num) {
        maxHeap.push_back(num);

        int current = maxHeap.size() - 1;
        while (current > 1 && (maxHeap[current] > maxHeap[parent(current)])) {
            std::swap(maxHeap[parent(current)], maxHeap[current]);
            current = parent(current);
        }
    }

    int pop(std::vector<int>& heap) {
        if (heap.size() < 2) {
            return -1;
        }

        if (heap.size() == 2) {
            int onlyElement = heap.back();
            heap.pop_back();
            return onlyElement;
        }

        int maximum = heap[1];

        heap[1] = heap.back();
        heap.pop_back();
        int current = 1;
        while (left(current) < heap.size()) {
            if (right(current) < heap.size() &&
                heap[right(current)] > heap[left(current)] &&
                heap[right(current)] > heap[current]) {
                std::swap(heap[right(current)], heap[current]);
                current = right(current);
            } else if (heap[left(current)] > heap[current]) {
                std::swap(heap[left(current)], heap[current]);
                current = left(current);
            } else {
                break;
            }
        }

        return maximum;
    }
};
