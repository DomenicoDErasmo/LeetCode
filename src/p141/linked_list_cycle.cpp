#include <iostream>
#include <set>

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *in_next) : val(x), next(in_next) {}
    ~Node() { delete next; }
};

class Solution
{
public:
    bool hasCycle(Node *head)
    {
        std::set<Node *> visited;
        Node *temp = head;
        while (temp)
        {
            if (visited.find(temp) != visited.end())
            {
                return true;
            }
            else
            {
                visited.insert(temp);
                temp = temp->next;
            }
        }
        return false;
    }
};

int main()
{
    std::cout << "Hello world!" << std::endl;
    return 0;
}