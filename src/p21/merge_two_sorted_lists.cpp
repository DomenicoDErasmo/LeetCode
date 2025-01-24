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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *prev = new ListNode(), **head = &(prev->next);
        while (list1 && list2)
        {
            ListNode **temp = &(list1->val < list2->val ? list1 : list2);
            prev->next = *temp;
            prev = prev->next;
            *temp = (*temp)->next;
        }

        prev->next = list1 ? list1 : list2;

        return *head;
    }
};