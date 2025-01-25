#include <iostream>

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    ~Node() { delete next; }
};

class Solution
{
public:
    Node *getIntersectionNode(Node *headA, Node *headB)
    {
        if (headA == headB)
        {
            return headA;
        }

        if (getLength(headA) > getLength(headB))
        {
            return intersectionHelper(headA, headB);
        }
        else
        {
            return intersectionHelper(headB, headA);
        }
    }

private:
    Node *intersectionHelper(Node *larger, Node *smaller)
    {
        Node *largerTemp = larger;

        while (largerTemp)
        {
            Node *smallerTemp = smaller;
            while (smallerTemp)
            {
                if (largerTemp == smallerTemp)
                {
                    return largerTemp;
                }
                smallerTemp = smallerTemp->next;
            }
            largerTemp = largerTemp->next;
        }
        return nullptr;
    }

    int getLength(Node *head)
    {
        int result = 0;
        Node *temp = new Node();
        temp->next = head;

        while (temp->next)
        {
            result++;
            temp = temp->next;
        }

        return result;
    }
};

int main()
{
    std::cout << "Hello world!" << std::endl;
    return 0;
}