struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(nullptr) {}
};

class Solution
{
public:
    Node *mergeTwoLists(Node *list1, Node *list2)
    {
        Node *prev = new Node(), **head = &(prev->next);
        while (list1 && list2)
        {
            Node **temp = &(list1->val < list2->val ? list1 : list2);
            prev->next = *temp;
            prev = prev->next;
            *temp = (*temp)->next;
        }

        prev->next = list1 ? list1 : list2;

        return *head;
    }
};