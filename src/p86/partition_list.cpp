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
    Node *partition(Node *head, int x)
    {
        Node *before = new Node(0), *before_temp = before, *after = new Node(0), *after_temp = after;

        Node *temp = head;
        while (temp)
        {
            if (temp->val < x)
            {
                before_temp->next = temp;
                before_temp = before_temp->next;
            }
            else
            {
                after_temp->next = temp;
                after_temp = after_temp->next;
            }
            temp = temp->next;
        }

        before_temp->next = after->next;
        after_temp->next = nullptr;
        return before->next;
    }
};

int main()
{
    std::cout << "Hello world!" << std::endl;
    return 0;
}