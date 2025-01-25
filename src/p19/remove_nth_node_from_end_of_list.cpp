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
    Node *removeNthFromEnd(Node *head, int n)
    {
        int length = getLength(head);

        // in case we want to delete the head
        if (length == n)
        {
            Node *new_head = head->next;
            head->next = nullptr;
            delete head;
            return new_head;
        }

        Node *temp = head;
        /* Let's say we have 5 nodes: 0, 1, 2, 3, 4
         * Let n = 2
         * We want to delete the 2nd to last node: 3
         * To do this, we need to get to node 2
         * length - n - 1 = 5 - 2 - 1 = 2, so we go through the loop twice: i = 0, i = 1
         * temp = temp->next: temp goes from 0 to 1, then from 1 to 2 - done!
         */
        for (int i = 0; i < length - n - 1; i++)
        {
            temp = temp->next;
        }

        // assume to_delete isn't null due to constraints in the problem: 1 <= n <= sz
        Node *to_delete = temp->next, *new_next = to_delete->next;
        temp->next = to_delete->next;

        // linked lists often have a recursive destructor, so set to_delete->next to null
        to_delete->next = nullptr;
        delete to_delete;

        return head;
    }

private:
    int getLength(Node *head)
    {
        int result = 0;

        while (head)
        {
            head = head->next;
            result++;
        }

        return result;
    }
};

int main()
{
    std::cout << "Hello world!" << std::endl;
    return 0;
}