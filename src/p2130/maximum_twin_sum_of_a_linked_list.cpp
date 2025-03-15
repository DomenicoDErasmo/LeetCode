#include <vector>  // max, vector

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    int pairSum(ListNode *head) {
        std::vector<int> values = fromList(head);
        int result = 0, left = 0, right = values.size() - 1;
        while (left < right) {
            result = std::max(result, values[left] + values[right]);
            left++;
            right--;
        }
        return result;
    }

   private:
    std::vector<int> fromList(ListNode *head) {
        std::vector<int> result;
        ListNode *temp = head;
        while (temp) {
            result.push_back(temp->val);
            temp = temp->next;
        }
        return result;
    }
};
