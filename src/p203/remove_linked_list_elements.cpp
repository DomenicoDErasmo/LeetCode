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
    Node *removeElements(Node *head, int val)
    {
        if (nullptr == head)
        {
            return head;
        }

        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};

int main()
{
    std::cout << "Hello world!" << std::endl;
    return 0;
}