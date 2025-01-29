#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        return mergeKListsMergeSort(lists);
    }

private:
    ListNode *mergeKListsMergeSort(std::vector<ListNode *> &lists)
    {
        // merge sort!
        return mergeHelper(lists, 0, lists.size() - 1);
    }

    ListNode *mergeHelper(std::vector<ListNode *> &lists, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        if (start == end)
        {
            return lists[start];
        }
        int mid = (end + start) / 2;
        ListNode *left = mergeHelper(lists, start, mid);
        ListNode *right = mergeHelper(lists, mid + 1, end);
        return merge(left, right);
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (!left)
        {
            return right;
        }

        if (!right)
        {
            return left;
        }

        if (left->val < right->val)
        {
            left->next = merge(left->next, right);
            return left;
        }
        else
        {
            right->next = merge(left, right->next);
            return right;
        }
    }
};