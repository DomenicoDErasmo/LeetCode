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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

class Solution
{
public:
    TreeNode *sortedListToBST(Node *head)
    {
        return sortedListToBST(head, nullptr);
    }

private:
    TreeNode *sortedListToBST(Node *start, Node *end)
    {
        if (start == end)
            return nullptr;

        Node *mid = start, *fast = start;

        // need to check both becasue fast is incremented twice
        while (fast != end && fast->next != end)
        {
            fast = fast->next->next;
            mid = mid->next;
        }

        return new TreeNode(
            mid->val,
            sortedListToBST(start, mid),
            sortedListToBST(mid->next, end));
    }
};

int main()
{
    std::cout << "Hello world!" << std::endl;
    return 0;
}