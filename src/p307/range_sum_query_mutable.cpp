#include <vector>  // vector

class SegmentTree {
   public:
    int sum, leftBound, rightBound;
    SegmentTree *leftChild, *rightChild;

    SegmentTree(int total, int L, int R)
        : sum(total),
          leftBound(L),
          rightBound(R),
          leftChild(nullptr),
          rightChild(nullptr) {}

    static SegmentTree *build(std::vector<int> &nums, int L, int R) {
        if (L == R) {
            return new SegmentTree(nums[L], L, R);
        }

        SegmentTree *root = new SegmentTree(0, L, R);
        int mid = (L + R) / 2;
        root->leftChild = build(nums, L, mid);
        root->rightChild = build(nums, mid + 1, R);
        root->sum = root->leftChild->sum + root->rightChild->sum;

        return root;
    }

    void update(int index, int val) {
        if (leftBound == rightBound) {
            sum = val;
            return;
        }

        int mid = (leftBound + rightBound) / 2;
        if (index > mid) {
            rightChild->update(index, val);
        } else {
            leftChild->update(index, val);
        }

        sum = leftChild->sum + rightChild->sum;
    }

    int rangeQuery(int left, int right) {
        if (left == leftBound && right == rightBound) {
            return sum;
        }

        int mid = (leftBound + rightBound) / 2;

        if (left > mid) {
            return rightChild->rangeQuery(left, right);
        } else if (right <= mid) {
            return leftChild->rangeQuery(left, right);
        } else {
            return leftChild->rangeQuery(left, mid) +
                   rightChild->rangeQuery(mid + 1, right);
        }
    }
};

class NumArray {
   public:
    NumArray(std::vector<int> &nums) {
        root = SegmentTree::build(nums, 0, nums.size());
    }

    void update(int index, int val) { root->update(index, val); }

    int sumRange(int left, int right) { return root->rangeQuery(left, right); }

   private:
    SegmentTree *root;
};