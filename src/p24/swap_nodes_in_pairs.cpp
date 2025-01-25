#include <iostream>

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
    ~Node() { delete next; }
};

class Solution
{
public:
    Node *swapPairs(Node *head)
    {
        if (!head)
        {
            return nullptr;
        }
        if (!head->next)
        {
            return head;
        }

        Node *temp = head, *new_head = temp->next, *next = temp->next, *prev = nullptr;
        // if we have an odd number of nodes, we don't want to swap the last one
        // so we check that both the current node and the next node aren't null
        while (temp && temp->next)
        {
            if (prev)
            {
                prev->next = next;
            }
            temp->next = next->next;
            next->next = temp;
            prev = temp;
            temp = temp->next;
            if (temp)
            {
                next = temp->next;
            }
        }
        return new_head;
    }
};

int main()
{
    std::cout << "Hello world!" << std::endl;
}