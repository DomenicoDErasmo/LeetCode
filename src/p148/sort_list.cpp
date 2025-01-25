#include <iostream>

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
    Node *sortList(Node *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        Node *temp = nullptr, *slow = head, *fast = head;

        // get middle
        while (fast && fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;
        Node *l1 = sortList(head);
        Node *l2 = sortList(slow);
        return mergeList(l1, l2);
    }

private:
    Node *mergeList(Node *&l1, Node *&l2)
    {
        Node *result = new Node(0, nullptr), *current = result;
        while (l1 && l2)
        {
            Node **chosen = l1->val < l2->val ? &l1 : &l2;
            current->next = *chosen;
            *chosen = (*chosen)->next;
            current = current->next;
        }
        current->next = l1 ? l1 : l2;
        return result->next;
    }
};

int main()
{
    std::cout << "Hello world!" << std::endl;
    return 0;
}