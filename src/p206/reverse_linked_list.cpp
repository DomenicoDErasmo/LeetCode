struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

class Solution
{
public:
    Node *reverseList(Node *head)
    {
        if (!head)
        {
            return head;
        }

        Node *temp = head, *prev = nullptr;
        while (temp)
        {
            Node *next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
};