#include <iostream>
#include <set>

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
    Node *deleteDuplicates(Node *head)
    {
        if (!head)
            return head;

        // traverse once over list and get list of duplicates
        std::set<int> duplicates;
        Node *temp = head;
        while (temp->next)
        {
            if (temp->val == temp->next->val && duplicates.find(temp->val) == duplicates.end())
            {
                duplicates.insert(temp->val);
            }
            temp = temp->next;
        }

        // first get the head
        while (head && duplicates.find(head->val) != duplicates.end())
        {
            head = head->next;
        }

        if (!head)
            return head;

        // next, iterate over and set next node = first node whose val not in set
        Node *prev = head;
        temp = head->next;
        while (temp)
        {
            while (temp && (duplicates.find(temp->val) != duplicates.end()))
            {
                temp = temp->next;
            }
            prev->next = temp;
            prev = temp;
            if (temp)
            {
                temp = temp->next;
            }
        }

        return head;
    }
};

int main()
{
    std::cout << "Hello world!" << std::endl;
    return 0;
}