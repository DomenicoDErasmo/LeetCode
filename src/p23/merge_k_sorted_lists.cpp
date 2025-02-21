#include <vector>

struct DoubleListNode {
    int val;
    DoubleListNode *next;
    DoubleListNode() : val(0), next(nullptr) {}
    DoubleListNode(int x) : val(x), next(nullptr) {}
    DoubleListNode(int x, DoubleListNode *next) : val(x), next(nullptr) {}
};

class Solution {
   public:
    DoubleListNode *mergeKLists(std::vector<DoubleListNode *> &lists) {
        return mergeKListsMergeSort(lists);
    }

   private:
    DoubleListNode *mergeKListsMergeSort(std::vector<DoubleListNode *> &lists) {
        // merge sort!
        return mergeHelper(lists, 0, lists.size() - 1);
    }

    DoubleListNode *mergeHelper(std::vector<DoubleListNode *> &lists, int start,
                                int end) {
        if (start > end) {
            return nullptr;
        }
        if (start == end) {
            return lists[start];
        }
        int mid = (end + start) / 2;
        DoubleListNode *left = mergeHelper(lists, start, mid);
        DoubleListNode *right = mergeHelper(lists, mid + 1, end);
        return merge(left, right);
    }

    DoubleListNode *merge(DoubleListNode *left, DoubleListNode *right) {
        if (!left) {
            return right;
        }

        if (!right) {
            return left;
        }

        if (left->val < right->val) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }
};