#include <iostream>
#include <set>

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    Node *detectCycle(Node *head)
    {
        Node *result = nullptr;
        std::set<Node *> visited;
        Node *temp = head;
        while (temp)
        {
            if (visited.find(temp) == visited.end())
            {
                visited.insert(temp);
                temp = temp->next;
            }
            else
            {
                result = temp;
                break;
            }
        }
        return result;
    }
};

int main()
{
    std::cout << "Hello world!" << std::endl;
    return 0;
}