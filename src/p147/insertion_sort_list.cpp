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
    Node *insertionSortList(Node *head)
    {
        Node *result = nullptr;
        insertNode(result, head, 0);
        Node *temp = head->next;

        // iterate through and insert the next element each time
        while (temp)
        {
            int pos = findSortedPos(result, temp->val);
            insertNode(result, temp, pos);
            temp = temp->next;
        }
        return result;
    }

private:
    int findSortedPos(Node *head, int val)
    {
        int result = 0;
        while (head && val > head->val)
        {
            head = head->next;
            result++;
        }
        return result;
    }
    void insertNode(Node *&head, Node *node, int pos)
    {
        Node *to_insert = new Node(node->val);

        if (!head || pos == 0)
        {
            // inserting at head
            to_insert->next = head;
            head = to_insert;
        }
        else
        {
            // inserting elsewhere in the list
            int i = 0;
            Node *temp = head, *prev = nullptr;
            while (i < pos)
            {
                prev = temp;
                temp = temp->next;
                i++;
            }
            prev->next = to_insert;
            to_insert->next = temp;
        }
    }
};

int main()
{
    std::cout << "Hello world!" << std::endl;
    return 0;
}