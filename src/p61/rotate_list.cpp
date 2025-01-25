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
    Node *rotateRight(Node *head, int k)
    {
        // edge-case: no order to change
        if (!head || !head->next)
        {
            return head;
        }

        size_t size = getSize(head);

        // k can be > size
        k = k % size;

        // edge-case: rotating by the total number of nodes will get us back to where we started
        if (!k)
        {
            return head;
        }

        // find the new head and cut off the previous node's connection to it to avoid a circular list
        Node *new_head = head, *prev = nullptr;
        for (size_t i = 0; i < size - k; i++)
        {
            prev = new_head;
            new_head = new_head->next;
        }
        prev->next = nullptr;

        // set the end of the new head to point to the old head
        Node *temp = new_head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = head;

        return new_head;
    }

private:
    size_t getSize(Node *head)
    {
        size_t result = 0;
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